/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elleagn <elleagn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:54:53 by elleagn           #+#    #+#             */
/*   Updated: 2024/07/18 16:55:39 by elleagn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_process
{
	int		infile;
	int		outfile;
	char	**args;
	int		error_number;
	int		error_message;
}				t_process;

#endif
