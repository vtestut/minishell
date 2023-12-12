/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:29:20 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/09 19:18:57 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"
#include "exec.h"
#include "utils.h"

void	exec_exit(void)
{
	struct s_glob_exec	*eglob;
	int					tmp;

	eglob = &(msh_glob_get()->exec);
	if (eglob->read_that > 0)
		close(eglob->read_that);
	ft_btree_delete_type(eglob->tree,
		(void (*)(void *, t_ft_btree_node_type))msh_free_cmdinfo);
	tmp = eglob->exit_status;
	ft_memset(eglob, 0, sizeof(struct s_glob_exec));
	eglob->read_that = -1;
	eglob->exit_status = tmp;
	msh_glob_get()->sig = 0;
}
