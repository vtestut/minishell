/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_foreachnd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:56:46 by pierre            #+#    #+#             */
/*   Updated: 2023/06/12 17:58:35 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_bree_foreachnd(t_ft_btree_node *tree, void (*f)(t_ft_btree_node *))
{
	if (!tree)
		return ;
	f(tree);
	ft_bree_foreachnd(tree->first, f);
	ft_bree_foreachnd(tree->second, f);
}
