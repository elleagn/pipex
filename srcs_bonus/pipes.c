/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:01:05 by gozon             #+#    #+#             */
/*   Updated: 2024/08/06 12:23:02 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Closes the file descriptors in a NULL-terminated array of integer pairs.
// Each pair represents a pipe, with two elements: [read_fd, write_fd].
void	close_pipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

// Creates an array of pipes, each represented by a pair of file descriptors.
// Allocates a NULL-terminated array of integer pairs, where each pair is a
// pipe.
// Returns the array on success, or NULL if a syscall or allocation error
// occurs.
int	**create_pipes(int size)
{
	int	**pipes;
	int	i;

	pipes = ft_calloc(size + 1, sizeof(int *));
	if (!pipes)
		return (perror("malloc"), NULL);
	i = 0;
	while (i < size)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i])
			return (perror("malloc"), free_int_array(pipes), NULL);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (pipe(pipes[i]) < 0)
			return (perror("pipe"), close_pipes(pipes), free_int_array(pipes),
				NULL);
		i++;
	}
	return (pipes);
}

// create_pipes

// void	ft_printtab(int **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		ft_printf("%d ", tab[i][0]);
// 		ft_printf("%d\n", tab[i][1]);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	int	**pipes;

// 	pipes = create_pipes(5);
// 	if (pipes)
// 	{
// 		ft_printtab(pipes);
// 		close_pipes(pipes);
// 		free_int_tab(pipes);
// 	}
// 	return (0);
// }
