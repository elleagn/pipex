/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:24:58 by gozon             #+#    #+#             */
/*   Updated: 2024/07/19 14:02:33 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

// int	main(void)
// {
// 	int		fd;
// 	char	*args[] = {"/usr/bin/cat", "-d", NULL};

// 	fd = open("infile", O_WRONLY);
// 	dup2(fd, STDERR_FILENO);
// 	execve(args[0], args, environ);
// 	return (1);
// }

int	main(void)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < 5)
	{
		pid = fork();
		if (pid == 0)
		{
			perror(ft_itoa(i));
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	while (wait(NULL) > 0)
		continue ;
	return (0);
}
