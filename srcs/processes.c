/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:32:23 by gozon             #+#    #+#             */
/*   Updated: 2024/07/19 14:08:10 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_process	*init_process(void)
{
	t_process	*process;

	process = malloc(sizeof(t_process));
	if (!process)
		return (perror("init_process"), NULL);
	process->in = -1;
	process->out = -1;
	process->args = NULL;
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

t_process	*setup_process(char *cmd, char **path, int in, int out)
{
	t_process	*process;

	process = init_process();
	if (!process)
		return (NULL);
	process->args = get_args(process, cmd, path);
	if (!process->args)
		return (NULL);
}
