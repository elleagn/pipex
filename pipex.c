/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:40:12 by gozon             #+#    #+#             */
/*   Updated: 2024/07/17 18:25:47 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_files(int fd[2], int **pipes, int i, char **av)
{
	if (i == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] < 0)
		{
			perror(av[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
		fd[0] = pipes[i - 1][0];
	if (!pipes[i])
	{
		fd[1] = open(av[i + 3], O_CREAT | O_WRONLY, 0644);
		if (fd[1] < 0)
		{
			perror(av[i + 3]);
			exit(EXIT_FAILURE);
		}
	}
	else
		fd[1] = pipes[i][1];
}

void	cmd_to_file(int **pipes, char **args, int i, t_cl_args *cl_args)
{
	int	fd[2];
	int	tmp;

	setup_files(fd, pipes, i, cl_args->av);
	tmp = dup2(fd[0], STDIN_FILENO);
	if (tmp < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (i == 0)
		close(fd[0]);
	if (!pipes[i])
		close(fd[1]);
	close_pipes(pipes);
	execve(args[0], args, cl_args->envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

int	exec_cmds(t_cl_args *cl_args, char **path, int **pipes)
{
	int		pid;
	char	**args;
	int		i;
	int		error;

	i = 0;
	while (i < cl_args->cmd_nb)
	{
		args = get_args(cl_args->av[i + 2], path);
		if (!args || args[0] == NULL)
			break ;
		pid = fork();
		if (pid == 0)
			cmd_to_file(pipes, args, i, cl_args);
		free_char_tab(args);
		if (pid < 0)
		{
			perror("fork");
			break ;
		}
		i++;
	}
	error = errno;
	close_pipes(pipes);
	while (wait(NULL) > 0)
		continue ;
	return (error);
}

int	pipex(t_cl_args *cl_args, char **path)
{
	int		**pipes;
	int		error;

	pipes = create_pipes(cl_args->cmd_nb - 1);
	error = exec_cmds(cl_args, path, pipes);
	free_int_tab(pipes);
	return (error);
}
