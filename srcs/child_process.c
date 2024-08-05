/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:18:55 by gozon             #+#    #+#             */
/*   Updated: 2024/08/05 21:42:26 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_unused_files(t_process **processes, int pos)
{
	int	i;

	i = 0;
	while (processes[i])
	{
		if (i != pos)
		{
			if (processes[i]->fd[0] >= 0)
				close(processes[i]->fd[0]);
			if (processes[i]->fd[1] >= 0)
				close(processes[i]->fd[1]);
		}
		i++;
	}
}

int	child_process(t_process **processes, int i, char **envp)
{
	close_unused_files(processes, i);
	if (dup2(processes[i]->fd[0], STDIN_FILENO) < 0)
	{
		close(processes[i]->fd[0]);
		close(processes[i]->fd[1]);
		perror("dup2");
		exit(-1);
	}
	close(processes[i]->fd[0]);
	if (dup2(processes[i]->fd[1], STDOUT_FILENO) < 0)
	{
		close(processes[i]->fd[1]);
		perror("dup2");
		exit(-1);
	}
	close(processes[i]->fd[1]);
	execve(processes[i]->cmd[0], processes[i]->cmd, envp);
	perror("execve");
	return (-1);
}
