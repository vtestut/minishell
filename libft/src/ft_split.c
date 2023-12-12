/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:26:55 by pierre            #+#    #+#             */
/*   Updated: 2023/02/05 23:30:02 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *str, int c)
{
	char	charset[2];

	charset[0] = c;
	charset[1] = 0;
	return (ft_splitcs(str, charset));
}
