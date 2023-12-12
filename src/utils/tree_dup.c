/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:02:49 by pierre            #+#    #+#             */
/*   Updated: 2023/11/23 17:53:26 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "exec.h"

/**
 * Duplicate the content of a node
 *
 * @param content
 * @param type
 * @return
 */
void	*tree_dup(void *content, t_ft_btree_node_type type)
{
	t_list_lexer			*dup_lex;
	union u_tree_content	*tmp[2];

	tmp[0] = content;
	tmp[1] = NULL;
	if (type == PP_COMMAND)
	{
		tmp[1] = malloc(sizeof(union u_tree_content));
		if (!tmp[1])
			return (NULL);
		dup_lex = ft_lstdup(tmp[0]->pcdata,
				(void *(*)(void *))msh_lexer_data_dup,
				(void (*)(void *))msh_lexer_free_data).lexer;
		if (!dup_lex)
			return (NULL);
		tmp[1]->command = exec_gen_cmdinfo(dup_lex);
	}
	else if (type == PP_PIPE)
		return ((void *)1);
	return (tmp[1]);
}
