/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:29:52 by gozon             #+#    #+#             */
/*   Updated: 2024/07/17 18:37:32 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"

void	ft_printtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
	ft_printf("%s\n", tab[i]);
}

int	main(int ac, char **av)
{
	char	**splitted;

	if (ac != 3)
	{
		ft_printf("wrong number of arguments");
		return (1);
	}
	splitted = ft_split(av[1], av[2][0]);
	if (!splitted)
		return (1);
	ft_printtab(splitted);
	return (0);
}
