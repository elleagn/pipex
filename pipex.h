/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:51:43 by gozon             #+#    #+#             */
/*   Updated: 2024/07/17 14:09:22 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "Libft/libft.h"

typedef struct s_cl_args
{
	int		cmd_nb;
	char	**av;
	char	**envp;
}				t_cl_args;

int		**create_pipes(int size);
char	**get_args(char *arg, char **path);
void	close_pipes(int **pipes);
void	free_int_tab(int **tab);
void	free_char_tab(char **tab);
int		pipex(t_cl_args *cl_args, char **path);

#endif
