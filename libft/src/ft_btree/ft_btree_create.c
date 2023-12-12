/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:31:43 by pierre            #+#    #+#             */
/*   Updated: 2023/06/07 01:34:12 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_string.h"

t_ft_btree_node	*ft_btree_create(void *content, t_ft_btree_node_type type)
{
	t_ft_btree_node	*tree;

	tree = malloc(sizeof(t_ft_btree_node));
	if (!tree)
		return (NULL);
	ft_memset(tree, 0, sizeof (t_ft_btree_node));
	tree->type = type;
	tree->content = content;
	return (tree);
}
