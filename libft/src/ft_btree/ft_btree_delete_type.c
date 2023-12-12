/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_delete_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:51:25 by pducloux          #+#    #+#             */
/*   Updated: 2023/11/23 17:54:04 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_delete_type(t_ft_btree_node *tree, void (*del)
		(void *content, t_ft_btree_node_type type))
{
	if (!tree)
		return ;
	ft_btree_delete_type(tree->first, del);
	ft_btree_delete_type(tree->second, del);
	if (tree->content)
	{
		del(tree->content, tree->type);
		tree->content = NULL;
	}
	free(tree);
}
