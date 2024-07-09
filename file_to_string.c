/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:36:57 by gozon             #+#    #+#             */
/*   Updated: 2024/07/09 15:57:57 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

t_list	*f_to_list(int fd)
{
	char	buffer[11];
	char	*str;
	t_list	*node;
	int		readval;
	t_list	*list;

	readval = -2;
	list = NULL;
	while (readval)
	{
		readval = read(fd, buffer, 10);
		if (readval == -1)
			return (perror(NULL), ft_lstclear(&list, free), NULL);
		buffer[readval] = '\0';
		str = ft_strdup(buffer);
		if (!str)
			return (perror(NULL), ft_lstclear(&list, free), NULL);
		node = ft_lstnew(str);
		if (!node)
			return (perror(NULL), ft_lstclear(&list, free), free(str), NULL);
		ft_lstadd_back(&list, node);
	}
	return (list);
}

char	*list_to_str(t_list **list, size_t bufsize)
{
	char	*str;
	t_list	*node;

	str = malloc((bufsize * ft_lstsize(*list) + 1) * sizeof(char));
	if (!str)
	{
		perror(NULL);
		ft_lstclear(list, free);
		return (NULL);
	}
	node = *list;
	str[0] = '\0';
	while (node)
	{
		ft_strcat(str, node->content);
		node = node->next;
	}
	ft_lstclear(list, free);
	return (str);
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
	str = list_to_str(&lst, 10);
	ft_lstclear(&lst, free);
	if (close(fd))
	{
		ft_printf("%s : %s\n", path, strerror(errno));
		return (free(str), NULL);
	}
	return (str);
}

// f_to_str

// int	main(int ac, char **av)
// {
// 	(void) ac;
// 	ft_printf("%s", f_to_str(av[1]));
// 	return (0);
// }

// f_to_list

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		ft_printf("%s", (char *)(lst->content));
// 		lst = lst-> next;
// 	}
// }

// int	main (int ac, char **av)
// {
// 	int	fd;

// 	(void) ac;
// 	fd = open(av[1], O_RDONLY);
// 	print_list(f_to_list(fd));
// 	return (0);
// }
