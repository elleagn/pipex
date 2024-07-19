/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:51:43 by gozon             #+#    #+#             */
/*   Updated: 2024/07/19 08:58:44 by gozon            ###   ########.fr       */
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

typedef struct s_process
{
	int		in;
	int		out;
	char	**args;
	char	error_msg;
	int		error_nb;
}				t_process;

int		**create_pipes(int size);
char	**get_args(char *arg, char **path);
void	close_pipes(int **pipes);
void	free_int_tab(int **tab);
void	free_char_tab(char **tab);
#endif
