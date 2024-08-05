/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:17:31 by gozon             #+#    #+#             */
/*   Updated: 2024/07/31 19:41:05 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Extract the PATH variable as a string from envp

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

// Extracts the PATH variable as a char ** from envp

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
	free_charr(args->path);
	free(args);
}

// Takes the command line args and puts them in my args struct

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
	int			retval;

	args = create_args(argc, argv, envp);
	if (!args)
		return (-1);
	processes = init_proc_array(args->ncmd);
	if (!processes)
		return (clear_args(args), -1);
	retval = pipex(args, processes);
	clear_proc_array(processes);
	clear_args(args);
	return (retval);
}
