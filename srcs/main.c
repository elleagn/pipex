/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elleagn <elleagn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:05:48 by elleagn           #+#    #+#             */
/*   Updated: 2024/07/18 19:48:24 by elleagn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_process	*parent;
	t_process	*child;
	int			error;

	if (ac != 4)
	{
		ft_printf("wrong number of arguments");
		return (1);
	}
	parent = init_process();
	if (!parent)
		return (perror("malloc"), 1);
	child = init_process();
	if (!child)
		return (perror("malloc"), free(parent), 1);
	error = pipex(parent, child, av, envp);
	process_clear(parent);
	process_clear(child);
	return (error);
}
