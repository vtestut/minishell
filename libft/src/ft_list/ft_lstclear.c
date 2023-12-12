/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:02:51 by pducloux          #+#    #+#             */
/*   Updated: 2023/06/14 18:04:31 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstclear(t_list lst, void (*f)(void *content))
{
	t_list	tmp;

	if (!lst.list)
		return ;
	while (lst.list)
	{
		tmp.list = lst.list->next;
		f(lst.list->content);
		free(lst.list);
		lst = tmp;
	}
}
