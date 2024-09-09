/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:43:17 by gozon             #+#    #+#             */
/*   Updated: 2024/09/06 10:39:00 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

// Frees the string pointed to by str1, and replaces it with str2.
// str2 replaces the new string and is not freed.
void	replace(char **str1, char *str2)
{
	free(*str1);
	*str1 = str2;
}

// Joins 3 strings into a new created string.
// Returns the new string on success or NULL on failure.
// The caller is responsible for freeing the allocated memory.
char	*strjoin_three(char const *s1, char const *s2, char const *s3)
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

// Finds an executable file with the name of the command in the specified
// directories.
// Updates cmd with the path of the found executable.
// Returns -1 if there is an allocation error, 127 if the command is not found,
// and 0 on success.
int	find_bin(char **cmd, char **path)
{
	char	*bin;
	int		i;

	if (ft_strnstr(*cmd, "/", ft_strlen(*cmd)))
	{
		if (access(*cmd, X_OK))
			return (perror(*cmd), 127);
		if (is_directory(*cmd))
			return (ft_printf("%s: is a directory\n"), 126);
		return (0);
	}
	i = 0;
	while (path[i])
	{
		bin = strjoin_three(path[i], "/", *cmd);
		if (!bin)
			return (perror("malloc"), -1);
		if (!access(bin, X_OK))
			return (replace(cmd, bin), 0);
		free(bin);
		i++;
	}
	ft_printf("%s: command not found\n", *cmd);
	return (127);
}

// Parses a command string and stores it in the process command slot as a string
// array.
// Returns 0 on success, 127 if the command is not found, and -1 if an
// allocation error occurs.
int	initialize_process_cmd(t_process *process, char *cmd, char **path)
{
	process->cmd = ft_split(cmd, ' ');
	if (!process->cmd)
		return (perror("split"), -1);
	if (!process->cmd[0])
		return (ft_printf("%s: command not found\n", cmd), 127);
	return (find_bin(&(process->cmd[0]), path));
}

// Iterates through a process array and sets up the command to be executed by
// each process using the provided path and command line arguments.
// The error status of the command for each process is stored in errnb.
// Returns 0 on success and -1 if an allocation error occurs in any subfunction.
int	setup_process_cmds(t_process **processes, t_args args)
{
	int	i;

	i = 0;
	while (i < args.ncmd)
	{
		if (!processes[i]->errnb)
		{
			processes[i]->errnb = initialize_process_cmd(processes[i],
					args.argv[i + 2], args.path);
			if (processes[i]->errnb == -1)
				return (-1);
		}
		i++;
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
