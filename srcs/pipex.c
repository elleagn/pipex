/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:19:37 by gozon             #+#    #+#             */
/*   Updated: 2024/08/05 21:49:54 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

int	pipex(t_args args, t_process **processes)
{
	int		i;
	pid_t	pid;

	if (setup_process_pipes(processes, args))
		return (-1);
	if (setup_process_cmds(processes, args))
		return (close_process_files(processes), -1);
	i = 0;
	while (i < args.ncmd)
	{
		pid = fork();
		if (pid < -1)
		{
			perror("fork");
			processes[i]->errnb = -1;
			break ;
		}
		if (!pid && !processes[i]->errnb)
			child_process(processes, i, args.envp);
		i++;
	}
	close_process_files(processes);
	while (wait(NULL) > 0)
		continue ;
	return (processes[min(args.ncmd - 1, i)]->errnb);
}
