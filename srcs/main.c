/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elleagn <elleagn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:05:48 by elleagn           #+#    #+#             */
/*   Updated: 2024/07/18 17:51:33 by elleagn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_process	*parent;
	t_process	*child;

	if (ac != 4)
	{
		ft_printf("wrong number of arguments");
		return (1);
	}
	parent = malloc(sizeof(t_process));
	if (!parent)
		return (perror("malloc"), 1);
	child = malloc(sizeof(t_process));
	if (!child)
		return (perror("malloc"), free(parent), 1);
	return (pipex(parent, child, av, envp));
}
