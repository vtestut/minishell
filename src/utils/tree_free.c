/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:58:28 by pierre            #+#    #+#             */
/*   Updated: 2023/11/23 17:22:36 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	tree_free(void *content, t_ft_btree_node_type type)
{
	t_cmd_info	*cmd;

	if (type == PP_COMMAND)
	{
		cmd = content;
		ft_lstclear(cmd->command, (void (*)(void *)) msh_lexer_free_data);
		ft_lstclear(cmd->redir, (void (*)(void *)) msh_lexer_free_data);
		ft_lstclear(cmd->heredoc, (void (*)(void *))free_t_list_heredoc);
		if (cmd->heredoc_str)
			free(cmd->heredoc_str);
		if (cmd->fdin != STDIN_FILENO)
			close(cmd->fdin);
		else if (cmd->fdout != STDOUT_FILENO)
			close(cmd->fdout);
		free(cmd);
	}
	else if (type == PP_PIPE)
		free(content);
}
