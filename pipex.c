/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:40:12 by gozon             #+#    #+#             */
/*   Updated: 2024/07/16 10:24:52 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int ac, char **av, char path)
{
	int		**pipes;
	pid_t	pid;
	int		i;
	int		error;

	pipes = create_pipes(ac - 3);
	i = 0;
	while (i < ac - 2)
	{
		pid = fork();
		if (pid == 0)
			exec_cmd(i, av, path);
		else if (pid < 0)
		{
			perror("fork");
			break ;
		}
	}
	error = errno;
	while (wait(NULL) != ECHILD)
		continue ;
	close_pipes(pipes, ac - 3);
	free_int_tab(pipes);
	return (error);
}

