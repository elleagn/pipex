/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:38:17 by gozon             #+#    #+#             */
/*   Updated: 2024/07/10 13:50:20 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			path = ft_strdup(&envp[i][5]);
			if (!path)
				return (perror(NULL), NULL);
			return (path);
		}
		i++;
	}
	return (NULL);
}


int	pipex(char **av, char *path)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd))
		return (perror(NULL), 1);
	pid = fork();
	if (pid > 0)
	{
		if (execcmd(av[1], av[2], fd[1]))
			return (1);
		wait();
	}
	else if (pid == 0)
	{
		if (execcmd(fd[0], av[3], av[4]))
			return (1);
	}
	else
		return (perror(NULL), 1);
}

// get_path

// int	main(int ac, char **av, char **envp)
// {
// 	(void) av;
// 	(void) ac;
// 	ft_printf("%s", get_path(envp));
// 	return (0);
// }
