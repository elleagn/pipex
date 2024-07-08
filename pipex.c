/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:43:17 by gozon             #+#    #+#             */
/*   Updated: 2024/07/08 13:48:37 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(const char *path, int perm)
{
	int	access_res;

	access_res = 0;
	if (perm == 1 || perm == 3 || perm == 5 || perm == 7)
		access_res = access(path, X_OK);
	if (!access_res && (perm == 2 || perm == 3 || perm == 6 || perm == 7))
		access_res = access(path, W_OK);
	if (!access_res && (perm == 3 || perm == 4 || perm == 6 || perm == 7))
		access_res = access(path, R_OK);
	if (access_res)
		ft_printf("%s : %s\n", path, strerror(errno));
	return (access_res);
}

// check_access

int	main(int argc, char **argv)
{
	(void) argc;
	check_access(argv[1], atoi(argv[2]));
	return (0);
}
