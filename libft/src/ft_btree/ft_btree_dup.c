/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:00:29 by pducloux          #+#    #+#             */
/*   Updated: 2023/11/23 22:13:04 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_string.h"

t_ft_btree_node	*ft_btree_dup(t_ft_btree_node *tree,
					void *(*dup)(void *, t_ft_btree_node_type),
					void (*del)(void *, t_ft_btree_node_type))
{
	t_ft_btree_node	*new;

	if (!tree)
		return (NULL);
	new = malloc(sizeof(t_ft_btree_node));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_ft_btree_node));
	new->type = tree->type;
	if (tree->content)
		new->content = dup(tree->content, tree->type);
	if (tree->content && !new->content)
		return (ft_btree_delete_type(new, del), NULL);
	new->first = ft_btree_dup(tree->first, dup, del);
	if (tree->first && !new->first)
		return (ft_btree_delete_type(new, del), NULL);
	new->second = ft_btree_dup(tree->second, dup, del);
	if (tree->second && !new->second)
		return (ft_btree_delete_type(new, del), NULL);
	return (new);
}
