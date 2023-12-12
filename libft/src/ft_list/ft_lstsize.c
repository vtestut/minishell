/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:52:02 by pierre            #+#    #+#             */
/*   Updated: 2023/06/14 12:59:03 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_lstsize(t_list lst)
{
	int	i;

	i = 0;
	while (lst.list)
	{
		++i;
		lst.list = lst.list->next;
	}
	return (i);
}
