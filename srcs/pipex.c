/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elleagn <elleagn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:24:51 by elleagn           #+#    #+#             */
/*   Updated: 2024/07/18 19:46:42 by elleagn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_process *parent, t_process *child, char **av, char **envp)
{
	char	**path;
	int		fd[2];
	pid_t	pid;

	path = get_path(envp);
	if (!path)
		return (1);
	if (pipe(fd) < 0)
		return (perror("pipe"), free_tab(path), 1);
	setup_files(parent, child, av);
	setup_args(parent, child, av, path);
	fork();
	if (pid < 0)
		return (perror("fork"), close_pipes(fd), 1);
	if (pid > 0)
		parent_process(parent, envp);
	if (pid == 0)
		child_process(child, envp);
	return (0);
}
