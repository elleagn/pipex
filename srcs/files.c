/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:01:33 by gozon             #+#    #+#             */
/*   Updated: 2024/09/06 09:55:18 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	is_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

// Closes the input and output file descriptors for each process in the array.
void	close_process_files(t_process **processes)
{
	int	i;

	i = 0;
	while (processes[i])
	{
		if (processes[i]->fd[0] >= 0)
			close(processes[i]->fd[0]);
		if (processes[i]->fd[1] >= 0)
			close(processes[i]->fd[1]);
		i++;
	}
}

// Opens the specified file in read-only mode and stores the file descriptor in
// fd[0].
// Returns 1 on failure and 0 on success.
int	open_input_file(int *fd, char *file)
{
	fd[0] = open(file, O_RDONLY);
	if (fd[0] < 0)
		return (perror(file), 1);
	return (0);
}

// Opens the specified file in write-only mode, creating it if it does not
// exist, and stores the file descriptor in fd[1].
// Returns 1 on failure and 0 on success.
int	open_output_file(int *fd, char *file)
{
	fd[1] = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] < 0)
		return (perror(file), 1);
	return (0);
}

// Sets up file descriptors for input and output for each process in the array.
// Creates pipes between processes, opens the input file for the first process,
// and opens the output file for the last process based on the command line
// arguments.
// args.ncmd represents the number of commands to be executed in the pipeline.
// args.argv is the array of command-line arguments.
// Returns 0 on success and -1 on failure.
int	setup_process_pipes(t_process **processes, t_args args)
{
	int	**pipes;
	int	i;

	pipes = create_pipes(args.ncmd - 1);
	if (!pipes)
		return (-1);
	i = 0;
	while (i < args.ncmd)
	{
		if (i > 0)
			processes[i]->fd[0] = pipes[i - 1][0];
		if (i < args.ncmd - 1)
			processes[i]->fd[1] = pipes[i][1];
		i++;
	}
	processes[0]->errnb = open_input_file(processes[0]->fd, args.argv[1]);
	processes[i - 1]->errnb = open_output_file(processes[i - 1]->fd,
			args.argv[i + 2]);
	free_int_array(pipes);
	return (0);
}

// open_input_file and open_output_file

// int	main(void)
// {
// 	int	fd[2];

// 	open_input_file(fd, "infil");
// 	return (0);
// }
