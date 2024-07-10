/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:43:17 by gozon             #+#    #+#             */
/*   Updated: 2024/07/10 08:53:57 by gozon            ###   ########.fr       */
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
		ft_printf("%s: %s\n", path, strerror(errno));
	return (access_res);
}

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*res;
	int		len1;
	int		len2;
	int		len3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	res = malloc((len1 + len2 + len3 + 1) * sizeof(char));
	if (res == NULL)
		return (perror(NULL), NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	ft_strlcat(res, s3, len1 + len2 + len3 + 1);
	return (res);
}

char	*find_bin(char *cmd, char **path_tab)
{
	char	*path;
	int		i;

	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
	{
		if (check_access(cmd, 1))
			return (NULL);
		return (cmd);
	}
	i = 0;
	while (path_tab[i])
	{
		path = ft_strjoin_three(path_tab[i], "/", cmd);
		if (!path)
			return (perror(NULL), NULL);
		if (!access(path, X_OK))
			return (path);
		free(path);
		i++;
	}
	ft_printf("command not found: %s", cmd);
	return (NULL);
}

// check_access

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	check_access(argv[1], atoi(argv[2]));
// 	return (0);
// }

// find_bin

// int	main(int ac, char **av)
// {
// 	char	**path_tab;
// 	char	*str;

// 	path_tab = ft_split("/home/gozon/bin:/home/gozon/bin:/usr/local/sbin:"
// 			"/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:"
// 			"/usr/local/games:/snap/bin", ':');
// 	if (!path_tab)
// 		return (perror(NULL), 1);
// 	if (ac == 2)
// 	{
// 		str = find_bin(av[1], path_tab);
// 		if (str)
// 			ft_printf("%s", str);
// 	}
// 	return (0);
// }
