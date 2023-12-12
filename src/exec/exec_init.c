/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:36:11 by pierre            #+#    #+#             */
/*   Updated: 2023/11/17 22:36:11 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"
#include "exec.h"

void	exec_init(int argc, char **argv, char **envp)
{
	t_glob_exec	*eglob;

	(void)argc;
	(void)argv;
	(void)envp;
	eglob = &(msh_glob_get()->exec);
	ft_memset(eglob, 0, sizeof(t_glob_exec));
	eglob->read_that = -1;
	eglob->pid = -1;
	eglob->exit_status = 0;
}
