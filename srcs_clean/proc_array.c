/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:45:43 by gozon             #+#    #+#             */
/*   Updated: 2024/07/31 12:32:22 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	clear_proc_array(t_process **proc_array)
{
	int	i;

	i = 0;
	while (proc_array[i])
	{
		clear_process(proc_array[i]);
		i++;
	}
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
