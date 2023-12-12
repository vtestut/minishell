/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:24:35 by pierre            #+#    #+#             */
/*   Updated: 2023/07/24 17:45:16 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# ifdef FT_BTREE_CUSTOM_TYPE
#  include FT_BTREE_CUSTOM_TYPE
# else
#  include "ft_btree_type.h"
# endif
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

/**
 * Create a new binary tree
 *
 * @param content	the content of the first node
 * @return
 */
t_ft_btree_node	*ft_btree_create(void *content, t_ft_btree_node_type type);

t_ft_btree_node	*ft_btree_add(t_ft_btree_node *parent, int first,
					void *content, t_ft_btree_node_type type);

/**
 * Delete the given node and all subsequent children, children
 * are removed first.
 *
 * @param tree
 * @param f			a callback function to delete the content of each node,
 * 					if f is null the content will not be freed (useful when
 * 					using stack allocated values)
 */
void			ft_btree_delete(t_ft_btree_node *tree, void (*f)(void *));

/**
 * Delete the given node and all subsequent children, children are removed first.
 *
 * @param tree
 * @param f
 */
void			ft_btree_delete_type(t_ft_btree_node *tree,
					void (*f)(void *, t_ft_btree_node_type type));

/**
 * Execute f on the type and content of each node of tree (including
 * the root), the nodes are passed from left to right and
 * the upper nodes will be passed first
 *
 * @param tree
 * @param f
 */
void			ft_btree_foreach(t_ft_btree_node *tree,
					void (*f)(t_ft_btree_node_type, void *));

/**
 * Execute f on each node of tree (including the root), the nodes are passed from
 * left to right and from top to bottom
 * @param tree
 * @param f
 */
void			ft_btree_foreachnd(t_ft_btree_node *tree,
					void (*f)(t_ft_btree_node *));

t_ft_btree_node	*ft_btree_dup(t_ft_btree_node *tree,
					void *(*dup)(void *, t_ft_btree_node_type),
					void (del)(void *, t_ft_btree_node_type));

#endif
