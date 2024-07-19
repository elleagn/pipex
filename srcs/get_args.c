/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:43:17 by gozon             #+#    #+#             */
/*   Updated: 2024/07/19 15:02:58 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_char_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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

int	*find_bin(char **cmd, char **path)
{
	char	*bin;
	int		i;

	if (ft_strnstr(*cmd, "/", ft_strlen(*cmd)))
	{
		if (access(*cmd, X_OK))
			return (perror(*cmd), 127);
		return (0);
	}
	i = 0;
	while (path[i])
	{
		bin = ft_strjoin_three(path[i], "/", *cmd);
		if (!bin)
			return (perror("malloc"), -1);
		if (!access(bin, X_OK))
			return (replace(cmd, bin), 0);
		free(bin);
		i++;
	}
	ft_printf("%s: command not found", cmd);
	return (127);
}

int	get_args(t_process *process, char *cmd, char **path)
{
	process->args = ft_split(cmd, ' ');
	if (!process->args)
		return (perror("split"), -1);
	if (!process->args[0])
		return (ft_printf("%s: command not found", cmd), 127);
	return (find_bin(process, path));
}

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

// get_args

// void	ft_printtab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		ft_printf("%s\n", tab[i]);
// 		i++;
// 	}
// }

// int	main(int ac, char **av)
// {
// 	char	**path_tab;
// 	char	**args;

// 	path_tab = ft_split("/home/gozon/bin:/home/gozon/bin:/usr/local/sbin:"
// 			"/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:"
// 			"/usr/local/games:/snap/bin", ':');
// 	if (!path_tab)
// 		return (perror(NULL), 1);
// 	if (ac == 2)
// 	{
// 		args = get_args(av[1], path_tab);
// 		if (args)
// 		{
// 			ft_printtab(args);
// 			free_char_tab(args);
// 		}
// 	}
// 	free_char_tab(path_tab);

// 	return (0);
// }
