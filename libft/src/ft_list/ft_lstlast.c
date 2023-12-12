/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:53:22 by pierre            #+#    #+#             */
/*   Updated: 2023/06/14 12:59:13 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	ft_lstlast(t_list lst)
{
	if (!lst.list)
		return ((t_list){.list = NULL});
	while (lst.list->next)
		lst.list = lst.list->next;
	return (lst);
}
