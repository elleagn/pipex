/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:19:37 by gozon             #+#    #+#             */
/*   Updated: 2024/08/05 11:10:23 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	pipex(t_args *args, t_process **processes)
{
	int	i;

	if (setup_process_pipes(processes, args))
		return (-1);
	if (fill_cmds(processes, args))
		return (close_process_files(processes), -1);
	i = 0;
	while (i < args->ncmd)
	{
		processes[i]->pid = fork();
		if (processes[i]->pid < -1)
		{
			perror("fork");
			processes[i]->errnb = -1;
			break ;
		}
		if (!processes[i]->pid)
			child_process(processes[i]);
	}
	i = 0;
	close_process_files(processes);
	while (wait(NULL) > 0)
		continue ;
	return (processes[i]->errnb);
}
