/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:42:48 by pierre            #+#    #+#             */
/*   Updated: 2023/06/23 16:56:53 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	ft_btree_delete(t_ft_btree_node *tree, void (*f)(void *))
{
	if (!tree)
		return ;
	ft_btree_delete(tree->first, f);
	ft_btree_delete(tree->second, f);
	if (tree->content)
		f(tree->content);
	free(tree);
}
