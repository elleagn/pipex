/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:38:17 by gozon             #+#    #+#             */
/*   Updated: 2024/07/15 10:38:18 by gozon            ###   ########.fr       */
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

int	main(int ac, char **av, char **envp)
{
	char	**path;

	if (av < 5)
	{
		ft_printf("argument list too short\n");
		return (1);
	}
	path = get_path(envp);
	if (!path)
		return (errno);
	if (ft_strncmp("here_doc", av[1], 9))
		pipex(av, path, ac);
	else
		pipex_heredoc(av, path, ac);
	return (errno);
}
