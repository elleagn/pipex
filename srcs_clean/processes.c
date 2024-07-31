/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:38:21 by gozon             #+#    #+#             */
/*   Updated: 2024/07/31 12:15:11 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	clear_process(t_process *process)
{
	if (process)
	{
		free(process->cmd);
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
	process->pos = -1;
	process->pid = -1;
	return (process);
}
