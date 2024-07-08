/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:43:17 by gozon             #+#    #+#             */
/*   Updated: 2024/07/08 13:09:28 by gozon            ###   ########.fr       */
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
		ft_printf("%s : %s", path, strerror(errno));
	return (access_res);
}
// TODO : create fill_list to shorten function

char	*ftolist(char *path)
{
	t_list	*list;
	char	*buffer;
	int		read_val;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s : %s", path, strerror(errno));
		return (NULL);
	}
	read_val = -2;
	while (read_val)
	{
		buffer = malloc(10 * sizeof(char));
		if (!buffer)
		{
			perror(NULL);
			return (ft_lstclear(list, free), NULL);
		}
		read_val = read();
	}
}

// check_access

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	check_access(argv[1], atoi(argv[2]));
// 	return (0);
// }
