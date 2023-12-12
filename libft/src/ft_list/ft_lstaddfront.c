/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:48:13 by pierre            #+#    #+#             */
/*   Updated: 2023/06/14 12:59:21 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstaddfront(t_list *lst, t_list new)
{
	t_list	tmp;

	tmp = *lst;
	new.list->next = tmp.list;
	*lst = new;
}
