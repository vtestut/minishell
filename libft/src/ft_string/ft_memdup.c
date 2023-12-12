/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:28:08 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/27 14:28:09 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memdup(void *src, size_t n)
{
	void	*dst;

	dst = malloc(n);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, n);
	return (dst);
}
