/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:36:57 by gozon             #+#    #+#             */
/*   Updated: 2024/07/08 13:55:46 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*ftolist(int fd)
{
	char	*buffer;
	t_list	*list;
	int		readval;

	list = NULL;
	readval = -2;
	while (readval)
	{
		buffer = malloc(10 * sizeof(char));
		if (!buffer)
		{
			perror(NULL);
			ft_lstclear(&list, free);
			return (NULL);
		}
	}
}

char	*ftostr(char *path)
{
	int		fd;
	char	*str;
	t_list	*lst;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s : %s\n", path, strerror(errno));
		return (NULL);
	}
	lst = ftolist(fd);
	str = listjoin(lst);
	ft_lstclear(&lst, free);
	if (close(fd))
	{
		ft_printf("%s : %s\n", path, strerror(errno));
		return (free(str), NULL);
	}
	return (str);
}
