/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:50:34 by pierre            #+#    #+#             */
/*   Updated: 2023/11/23 18:19:35 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	create_command_init(t_list_lexer **lst,
				t_list l[2],
				t_list_lexer **before,
				t_list_lexer **iter)
{
	l[0] = (t_list){.lexer = *lst};
	l[1] = ft_lstdup(l[0],
			(void *(*)(void *))msh_lexer_data_dup,
			(void (*)(void *))msh_lexer_free_data);
	if (!l[1].list)
		return (0);
	*before = l[1].lexer;
	*iter = l[1].lexer;
	return (1);
}

/**
 * Extract a the command from a list of tokens
 *
 * Eg: ls -al >>f3 | cat
 *    |          |
 *    \_________/-->those tokens are a command and will be extracted
 *
 * Datas are duplicated to avoid double free
 *
 * @param lst
 *
 * @return
 */
t_ft_btree_node	*create_command(t_list_lexer **lst)
{
	t_list					tmp[2];
	t_list_lexer			*before;
	t_list_lexer			*iter;
	t_msh_lexer_data		*data;
	union u_tree_content	*content;

	if (!create_command_init(lst, tmp, &before, &iter))
		return (NULL);
	data = iter->content;
	while (iter && msh_parser_token_is_command(data->token))
	{
		before = iter;
		*lst = (*lst)->next;
		iter = iter->next;
		if (iter)
			data = iter->content;
	}
	before->next = NULL;
	ft_lstclear(iter, (void (*)(void *))msh_lexer_free_data);
	content = malloc(sizeof(union u_tree_content));
	if (!content)
		return (ft_lstclear(tmp[1].lexer,
				(void (*)(void *))msh_lexer_free_data), NULL);
	content->pcdata = tmp[1].lexer;
	return (ft_btree_create(content, PP_COMMAND));
}
