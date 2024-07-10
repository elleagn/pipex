/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:51:43 by gozon             #+#    #+#             */
/*   Updated: 2024/07/10 09:02:28 by gozon            ###   ########.fr       */
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

char	*f_to_str(char *path);
char	*find_bin(char *cmd, char **path_tab);

#endif
