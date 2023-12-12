/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:31:10 by pierre            #+#    #+#             */
/*   Updated: 2023/07/10 01:51:53 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_powi(int base, int power)
{
	int	ret;

	if (!base)
		return (0);
	else if (power == 0)
		return (1);
	ret = base;
	while (--power)
		ret *= base;
	return (ret);
}
