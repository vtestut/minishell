/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:01:36 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 16:01:44 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_TYPE_H
# define FT_BTREE_TYPE_H

# include <sys/types.h>

typedef u_int64_t	t_ft_btree_node_type;

typedef struct ft_btree_node {
	t_ft_btree_node_type	type;
	void					*content;
	struct ft_btree_node	*first;
	struct ft_btree_node	*second;
}	t_ft_btree_node;

#endif
