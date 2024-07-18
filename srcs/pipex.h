/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elleagn <elleagn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:58:59 by elleagn           #+#    #+#             */
/*   Updated: 2024/07/18 18:14:19 by elleagn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>

typedef struct s_process
{
	int		infile;
	int		outfile;
	char	**args;
	int		error_number;
	int		error_message;
}				t_process;

int	pipex(t_process *parent, t_process *child, char **av, char **envp);

#endif
