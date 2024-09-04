/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:38:21 by gozon             #+#    #+#             */
/*   Updated: 2024/08/05 18:20:32 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	clear_process(t_process *process)
{
	if (process)
	{
		free_str_array(process->cmd);
		free(process);
	}
}

t_process	*init_process(void)
{
	t_process	*process;

	process = malloc(sizeof(t_process));
	if (!process)
		return (perror("init_process"), NULL);
	process->fd[0] = -1;
	process->fd[1] = -1;
	process->cmd = NULL;
	process->errnb = 0;
	return (process);
}

void	clear_proc_array(t_process **proc_array)
{
	int	i;

	i = 0;
	while (proc_array[i])
	{
		clear_process(proc_array[i]);
		i++;
	}
	free(proc_array);
}

t_process	**init_proc_array(int size)
{
	t_process	**proc_array;
	int			i;

	proc_array = ft_calloc((unsigned)size + 1, sizeof(t_process *));
	if (!proc_array)
		return (perror("init_proc_array"), NULL);
	i = 0;
	while (i < size)
	{
		proc_array[i] = init_process();
		if (!proc_array[i])
		{
			clear_proc_array(proc_array);
			return (NULL);
		}
		i++;
	}
	return (proc_array);
}
