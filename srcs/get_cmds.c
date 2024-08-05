/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:43:17 by gozon             #+#    #+#             */
/*   Updated: 2024/08/05 10:08:09 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	replace(char **str1, char *str2)
{
	free(*str1);
	*str1 = str2;
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

int	find_bin(char **cmd, char **path)
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
	ft_printf("%s: command not found", *cmd);
	return (127);
}

int	get_cmd(t_process *process, char *cmd, char **path)
{
	process->cmd = ft_split(cmd, ' ');
	if (!process->cmd)
		return (perror("split"), -1);
	if (!process->cmd[0])
		return (ft_printf("%s: command not found", cmd), 127);
	return (find_bin(&(process->cmd[0]), path));
}

int	fill_cmds(t_process	**processes, t_args args)
{
	int	i;

	while (i < args.ncmd)
	{
		processes[i]->errnb = get_cmd(processes[i], args.argv[i + 2],
				args.path);
		if (processes[i]->errnb == -1)
			return (-1);
	}
	return (0);
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
// 	char		**path_tab;
// 	t_process	*process;

// 	path_tab = ft_split("/home/gozon/bin:/home/gozon/bin:/usr/local/sbin:"
// 			"/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:"
// 			"/usr/local/games:/snap/bin", ':');
// 	if (!path_tab)
// 		return (perror(NULL), 1);
// 	if (ac == 2)
// 	{
// 		process = init_process();
// 		if (process)
// 		{
// 			process->error_nb = get_args(process, av[1], path_tab);
// 			if (!process->error_nb)
// 				ft_printtab(process->args);
// 			destroy_process(process);
// 		}
// 	}
// 	free_char_tab(path_tab);
// 	return (0);
// }
