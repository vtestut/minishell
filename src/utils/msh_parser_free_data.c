/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser_free_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:01:18 by pierre            #+#    #+#             */
/*   Updated: 2023/11/26 19:01:18 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	msh_parser_free_data(union u_tree_content *content,
		t_ft_btree_node_type type)
{
	if (type == PP_COMMAND)
		ft_lstclear(content->pcdata, (void (*)(void *))msh_lexer_free_data);
	else
		free(content->pdata);
	free(content);
}
