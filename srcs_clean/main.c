/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:17:31 by gozon             #+#    #+#             */
/*   Updated: 2024/07/30 21:41:01 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

void	clear_args(t_args	*args)
{
	free(args->path);
	free(args);
}

t_args	*create_args(int argc, char **argv, char **envp)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->ncmd = argc - 3;
	args->argv = argv;
	args->envp = envp;
	args->path = get_path(envp);
	if (!args->path)
		return (NULL);
	return (args);
}

int	main(int argc, char **argv, char **envp)
{
	t_args		*args;
	t_process	**processes;

	args = create_args(argc, argv, envp);
	if (!args)
		return (-1);
	processes = init_proc_array(args->ncmd);
	if (!processes)
		return (clear_args(args), -1);
	clear_proc_array(processes);
	return (pipex(args, processes));
}
