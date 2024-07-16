/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:40:12 by gozon             #+#    #+#             */
/*   Updated: 2024/07/16 08:25:47 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int ac, char **av, char path)
{
	int		**pipes;
	pid_t	pid;
	int		i;

	pipes = create_pipes(ac - 3);
	i = 0;
	while (i < ac - 2)
	{
		fork();
	}

}
