/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:19:37 by gozon             #+#    #+#             */
/*   Updated: 2024/09/04 09:22:56 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

// Returns the smaller of two integers.
int	min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

// Sets up pipes, files, and commands for each process based on command-line
// arguments.
// Forks child processes to execute commands concurrently and waits for their
// completion.
// Closes open file descriptors but does not free the process array.
// Returns:
//   -1 on syscall failure or allocation error
//   127 if any command is not found
//   1 for other general errors such as file access issues
//   0 on success
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
