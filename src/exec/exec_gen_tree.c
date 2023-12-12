/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_gen_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:33:00 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 18:20:14 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "utils.h"

t_ft_btree_node	*exec_gen_tree(t_ft_btree_node *ptree)
{
	t_ft_btree_node	*etree;

	etree = ft_btree_dup(ptree, tree_dup, tree_free);
	if (!etree)
		return (NULL);
	return (etree);
}
