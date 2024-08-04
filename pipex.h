/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:21:34 by gozon             #+#    #+#             */
/*   Updated: 2024/07/31 18:32:50 by gozon            ###   ########.fr       */
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
	pid_t	pid;
}				t_process;

typedef struct s_args
{
	int		ncmd;
	char	**argv;
	char	**envp;
	char	**path;
}				t_args;

void		close_pipes(int **pipes);

// init functions

t_process	*init_process(void);
t_process	**init_proc_array(int size);
int			**create_pipes(int size);

// cleanup functions

void		free_strarr(char **array);
void		clear_proc_array(t_process **proc_array);
void		clear_process(t_process *process);

#endif
