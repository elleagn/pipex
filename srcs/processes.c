/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:32:23 by gozon             #+#    #+#             */
/*   Updated: 2024/07/19 09:09:11 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_process	*init_process(void)
{
	t_process	*process;

	process = malloc(sizeof(t_process));
	if (!process)
		return (perror("init_process"), NULL);
	process->in = 0;
	process->out = 0;
	process->args = NULL;
	process->error_msg = NULL;
	process->error_nb = 0;
	process->pid = -1;
	return (process);
}

void	destroy_process(t_process *process)
{
	free(process->args);
	free(process->args);
	free(process);
}
