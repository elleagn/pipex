/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:21:34 by gozon             #+#    #+#             */
/*   Updated: 2024/07/19 10:24:36 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_process
{
	int		in;
	int		out;
	char	**args;
	char	error_msg;
	int		error_nb;
	pid_t	pid;
}				t_process;

int		pipex(t_list *proclist, char **av, char **envp);
int		**create_pipes(int size);
void	close_pipes(int **pipes);

#endif
