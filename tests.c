/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:24:58 by gozon             #+#    #+#             */
/*   Updated: 2024/07/19 09:01:53 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

int	main(void)
{
	int		fd;
	char	*args[] = {"/usr/bin/cat", "-d", NULL};

	fd = open("infile", O_WRONLY);
	dup2(fd, STDERR_FILENO);
	execve(args[0], args, environ);
	return (1);
}
