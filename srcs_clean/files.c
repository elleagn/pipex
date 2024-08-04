/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:01:33 by gozon             #+#    #+#             */
/*   Updated: 2024/08/04 12:50:07 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	open_in(int *fd, char *file)
{
	fd[0] = open(file, O_RDONLY);
	if (fd[0] < 0)
		return (perror(file), 1);
	return (0);
}

int	open_out(int *fd, char *file)
{
	fd[1] = open(file, O_WRONLY | O_CREAT, 0644);
	if (fd[1] < 0)
		return (perror(file), 1);
	return (0);
}

int	fill_files(t_process **processes, t_args *args)
{
	int	**pipes;
	int	i;

	pipes = create_pipes(args->ncmd - 1);
	if (!pipes)
		return (-1);
	i = 1;
	while (i < args->ncmd)
	{
		if (i > 0)
			processes[i]->fd[0] = pipes[i - 1][0];
		if (i < args->ncmd - 1)
			processes[i]->fd[1] = pipes[i][1];
	}
	processes[0]->errnb = open_in(processes[0]->fd, args->argv[1]);
	processes[i - 1]->errnb = open_out(processes[i - 1]->fd,
			args->argv[i + 1]);
	return (0);
}

// open_in and open_out

int	main(void)
{
	int	fd[2];

	open_in(fd, "infil");
	return (0);
}
