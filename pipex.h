/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:21:34 by gozon             #+#    #+#             */
/*   Updated: 2024/09/06 09:56:01 by gozon            ###   ########.fr       */
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

void		free_str_array(char **array);
void		clear_proc_array(t_process **proc_array);
void		clear_process(t_process *process);
void		free_int_array(int **tab);
void		close_process_files(t_process **processes);
void		clear_args(t_args	*args);

// processes filling functions

int			setup_process_pipes(t_process **processes, t_args args);
int			setup_process_cmds(t_process **processes, t_args args);
int			is_directory(char *file);

// Exec functions

int			child_process(t_process **processes, int i, t_args *args);
int			pipex(t_args *args, t_process **processes);

#endif
