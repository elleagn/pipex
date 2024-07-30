/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:17:31 by gozon             #+#    #+#             */
/*   Updated: 2024/07/30 21:25:50 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args		*args;
	t_process	**proctab;

	args = create_args(argc, argv, envp);
	if (!args)
		return (-1);
	proctab = init_proctab(args->ncmd);
	if (!proctab)
		return (clear_args(args), -1);
	clear_proctab(proctab);
	return (pipex(args, proctab));
}
