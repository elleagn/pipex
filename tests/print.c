/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:45:03 by gozon             #+#    #+#             */
/*   Updated: 2024/08/05 16:23:40 by gozon            ###   ########.fr       */
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
}

// int	main(void)
// {
// 	t_process	**procarr;
// 	int			i;

// 	procarr = init_proc_array(2);
// 	if (!procarr)
// 		return (ft_printf("null array\n"), 1);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		if (!procarr[i] || !procarr[i]->errnb == 0)
// 			return (ft_printf("pb with process"), 1);
// 		i++;
// 	}
// 	if (!procarr[i])
// 		ft_printf("OK\n");
// 	clear_proc_array(procarr);
// 	return (0);
// }
