/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:24:58 by gozon             #+#    #+#             */
/*   Updated: 2024/07/17 13:57:40 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int		fd[2];
	int		i;
	pid_t	pid;
	int		file;
	char	*arg[] = {"/usr/bin/cat", NULL};

	pipe(fd);
	i = 0;
	while (i < 2)
	{
		pid = fork();
		if (i == 0 && pid == 0)
		{
			close(fd[0]);
			file = open("infile", O_RDONLY);
			dup2(file, STDIN_FILENO);
			close(file);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			execve(arg[0], arg, NULL);
		}
		if (i == 1 && pid == 0)
		{
			close(fd[1]);
			file = open("outfile", O_WRONLY);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			dup2(file, STDOUT_FILENO);
			close(file);
			execve(arg[0], arg, NULL);
		}
	}
	close (fd[0]);
	return (0);
}
