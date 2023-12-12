/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:35:20 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/09 16:35:21 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_all_pipes(void)
{
	t_ft_btree_node	*tree;
	t_cmd_info		*cmd;

	tree = msh_glob_get()->exec.tree;
	while (tree && tree->type == PP_PIPE)
	{
		cmd = &(tree->first->content->command);
		if (cmd->fdin != STDIN_FILENO)
			close(cmd->fdin);
		if (cmd->fdout != STDOUT_FILENO)
			close(cmd->fdout);
		tree = tree->second;
	}
	cmd = &(tree->content->command);
	if (cmd->fdin != STDIN_FILENO)
		close(cmd->fdin);
}
