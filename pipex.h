/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:21:34 by gozon             #+#    #+#             */
/*   Updated: 2024/07/31 13:05:21 by gozon            ###   ########.fr       */
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

// pipes functions

int			**create_pipes(int size);
void		close_pipes(int **pipes);

// t_process and array of t_process functions

t_process	*init_process(void);
void		clear_process(t_process *process);
t_process	**init_proc_array(int size);
void		clear_proc_array(t_process **proc_array);

#endif
