/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free_cmdinfo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:13:54 by pierre            #+#    #+#             */
/*   Updated: 2023/11/24 15:45:47 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	msh_free_cmdinfo(union u_tree_content *content,
		t_ft_btree_node_type type)
{
	t_cmd_info	cmd;

	(void)type;
	if (!content)
		return ;
	if (type == PP_PIPE)
		return ;
	cmd = content->command;
	if (cmd.command)
		ft_lstclear(cmd.command, (void (*)(void *))msh_lexer_free_data);
	if (cmd.redir)
		ft_lstclear(cmd.redir, (void (*)(void *))msh_lexer_free_data);
	if (cmd.heredoc)
		ft_lstclear(cmd.heredoc, (void (*)(void *)) free_t_list_heredoc);
	if (cmd.heredoc_str)
		free(cmd.heredoc_str);
	if (cmd.fdin != STDIN_FILENO)
		close(cmd.fdin);
	else if (cmd.fdout != STDOUT_FILENO)
		close(cmd.fdout);
	free(content);
}
