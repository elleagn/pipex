/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:17:31 by gozon             #+#    #+#             */
/*   Updated: 2024/09/06 09:44:25 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Extracts the PATH environment variable value from envp as a string.
// Returns NULL if the PATH variable doesn't exist or if a memory allocation
// error occurs.
// On success, returns a newly allocated string containing the PATH value
// (excluding "PATH=").
// The caller is responsible for freeing the returned string.
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

// Extracts the PATH environment variable value from envp and splits it into an
// array of directory paths.
// Returns NULL if the PATH variable is not found, or if a memory allocation
// error occurs.
// On success, returns a NULL-terminated array of strings, each representing a
// directory in the PATH.
// The caller is responsible for freeing the array and its contents.
char	**get_path(char **envp)
{
	char	**path_tab;
	char	*path;

	path = get_path_str(envp);
	if (!path)
		return (NULL);
	path_tab = ft_split(path, ':');
	free(path);
	if (!path_tab || !path_tab[0])
		return (perror("ft_split"), NULL);
	return (path_tab);
}

// Frees the memory allocated for the t_args structure, including its
// array.
// Assumes that args->path is a NULL-terminated array of strings.
void	clear_args(t_args	*args)
{
	free_str_array(args->path);
	free(args);
}

// Creates and initializes a t_args structure from command line arguments and
// environment variables.
// Assumes argc is at least 4, with the format:
// ./pipex infile cmd1 cmd2 ... outfile
// Returns NULL on allocation failure or if the PATH variable cannot be
// retrieved.
// The caller is responsible for freeing the returned t_args structure using
// clear_args().
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

// Implements a shell-like pipeline execution program using multiple processes.
// Usage: ./pipex infile cmd1 cmd2 ... cmdN outfile
// Simulates shell behavior: < infile cmd1 | cmd2 | ... | cmdN > outfile
// Each command is executed in its own child process concurrently within the
// pipeline.
// Error Handling:
// - Returns -1 immediately if any system call (e.g., fork, execve, pipe) or
// memory allocation fails.
// - Continues execution for file errors or command not found errors.
// Return Value:
// - 0 if the pipeline completes successfully.
// - The exit status reflects the status of the last command in the pipeline,
// such as:
//   - 127 if a command is not found in the PATH.
//   - 1 if there is a general error (e.g., accessing a file, wrong number of
// argument etc.).
int	main(int argc, char **argv, char **envp)
{
	t_args		*args;
	t_process	**processes;
	int			retval;

	if (argc != 5)
		return (ft_printf("wrong number of arguments"), 1);
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
