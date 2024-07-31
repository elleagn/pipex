/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:45:03 by gozon             #+#    #+#             */
/*   Updated: 2024/07/31 11:43:01 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_printcharr(char **arr, char *sep)
{
	int	i;

	i = 0;
	if (arr)
	{
		ft_printf("%s", arr[0]);
		while (arr[++i])
			ft_printf("%s%s", sep, arr[0]);
	}
	ft_printf("\n");
}

void	print_process(t_process *process)
{
	ft_printf("fd: %i %i\n", process->fd[0], process->fd[1]);
	ft_printf("cmd: ");
	ft_printcharr(process->cmd, " ");
	ft_printf("errnb: %i\n", process->errnb);
	ft_printf("pos: %i\n", process->pos);
	ft_printf("pid: %i\n", process->pid);
}

int	main(void)
{
	print_process(init_process());
	return (0);
}
