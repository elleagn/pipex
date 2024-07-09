/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:36:57 by gozon             #+#    #+#             */
/*   Updated: 2024/07/09 09:07:06 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*f_to_list(int fd)
{
	t_list	*buffer;
	t_list	*list;
	int		readval;

	list = NULL;
	readval = -2;
	while (readval)
	{
		buffer = ft_lstnew(malloc(10 * sizeof(char)));
		if (!buffer || !(buffer->content))
		{
			perror(NULL);
			ft_lstclear(&list, free);
			ft_lstclear(&buffer, free);
			return (NULL);
		}
		readval = read(fd, buffer, 10);
		if (readval == -1)
			return (perror(NULL), ft_lstclear(&list, free),
				ft_lstclear(&buffer, free), NULL);
		ft_lstadd_back(&list, buffer);
	}
	return (list);
}

char	*list_to_str(t_list **list, int bufsize)
{
	char	*str;
}

char	*f_to_str(char *path)
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
	lst = f_to_list(fd);
	str = list_to_str(&lst);
	ft_lstclear(&lst, free);
	if (close(fd))
	{
		ft_printf("%s : %s\n", path, strerror(errno));
		return (free(str), NULL);
	}
	return (str);
}
