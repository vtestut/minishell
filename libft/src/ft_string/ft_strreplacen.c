/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplacen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:25:08 by pducloux          #+#    #+#             */
/*   Updated: 2023/11/13 19:25:10 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strreplacen(const char *src, size_t begin,
			size_t n, const char *what)
{
	char	*new;
	char	*tmp;

	tmp = ft_strremoven(src, begin, n);
	if (!tmp)
		return (NULL);
	new = ft_strinsertn(tmp, begin, what);
	if (!new)
		return (free(tmp), NULL);
	free(tmp);
	return (new);
}
