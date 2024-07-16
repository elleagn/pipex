/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:01:05 by gozon             #+#    #+#             */
/*   Updated: 2024/07/16 08:24:13 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	close_pipes(char **pipes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

int	**create_pipes(int size)
{
	int	*fd;
	int	**pipes;
	int	i;

	pipes = ft_calloc(size, sizeof(int *));
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < size)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i])
			return (free_tab(pipes, i), NULL);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (pipe(pipes[i]) < 0)
			return (close_pipes(pipes, i), freetab(pipes, size), NULL);
	}
	return (pipes);
}
