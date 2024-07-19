/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:31:26 by gozon             #+#    #+#             */
/*   Updated: 2024/07/19 10:17:30 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_str(char **envp)
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
				return (perror("malloc"), NULL);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	**get_path(char **envp)
{
	char	**path_tab;
	char	*path;

	path = get_path_str(envp);
	if (!path)
		return (NULL);
	path_tab = ft_split(path, ':');
	free(path);
	if (!path_tab)
		return (perror("ft_split"), NULL);
	return (path_tab);
}

int	pipex(t_list *proclist, char **av, char **envp)
{
	char	**path;
	int		**pipes;

	path = get_path(envp);
	if (!path)
		return (NULL);
	pipes = create_pipes(1);
	if (!pipes)
		return (free(path), NULL);
	proclist = setup_proclist(av, path, proclist, pipes);
	if (!proclist)
		return (free(path), close_pipes(pipes), NULL);
}
