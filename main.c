/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:38:17 by gozon             #+#    #+#             */
/*   Updated: 2024/07/17 14:17:41 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_var(char **envp)
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

char	**get_path_tab(char **envp)
{
	char	**path_tab;
	char	*path;

	path = get_path_var(envp);
	if (!path)
		return (NULL);
	path_tab = ft_split(path, ':');
	free(path);
	if (!path_tab)
		return (NULL);
	return (path_tab);
}

// int	main(int ac, char **av, char **envp)
// {
// 	char	**path;

// 	if (ac < 5)
// 	{
// 		ft_printf("argument list too short\n");
// 		return (1);
// 	}
// 	path = get_path_tab(envp);
// 	if (!path)
// 		return (errno);
// 	if (ft_strncmp("here_doc", av[1], 9))
// 		pipex(ac - 3, av, path);
// 	free_char_tab(path);
// 	return (errno);
// }

// Test main

int	main(int ac, char **av, char **envp)
{
	char		**path;
	t_cl_args	*cl_args;

	if (ac < 5)
	{
		ft_printf("argument list too short\n");
		return (1);
	}
	path = get_path_tab(envp);
	if (!path)
		return (errno);
	cl_args = malloc(sizeof(t_cl_args));
	if (!cl_args)
		return (free_char_tab(path), errno);
	cl_args->cmd_nb = ac - 3;
	cl_args->av = av;
	cl_args->envp = envp;
	if (ft_strncmp("here_doc", av[1], 9))
		pipex(cl_args, path);
	free_char_tab(path);
	free(cl_args);
	return (errno);
}
