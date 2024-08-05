/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:01:05 by gozon             #+#    #+#             */
/*   Updated: 2024/08/05 11:20:15 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Close the pipes described in a NULL terminated array of fd[2]

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

// Create size pipes and puts the fds in a null-terminated array

int	**create_pipes(int size)
{
	int	**pipes;
	int	i;

	pipes = ft_calloc(size + 1, sizeof(int *));
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < size)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i])
			return (free_int_array(pipes), NULL);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (pipe(pipes[i]) < 0)
			return (close_pipes(pipes), free_int_array(pipes), NULL);
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
