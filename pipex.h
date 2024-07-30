/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:21:34 by gozon             #+#    #+#             */
/*   Updated: 2024/07/30 21:27:17 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_process
{
	int		fd[2];
	char	**cmd;
	int		errnb;
	int		pos;
	pid_t	pid;
}				t_process;

typedef struct s_args
{
	int		ncmd;
	char	**argv;
	char	**envp;
	char	**path;
}				t_args;

int			**create_pipes(int size);
void		close_pipes(int **pipes);
t_process	*init_process(void);
void		destroy_process(t_process *process);

#endif
