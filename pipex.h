/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:51:43 by gozon             #+#    #+#             */
/*   Updated: 2024/07/16 10:32:29 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "Libft/libft.h"

int		**create_pipes(int size);
char	**get_args(char *arg, char **path);
void	close_pipes(int **pipes);
void	free_int_tab(int **tab);

#endif
