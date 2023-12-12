/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:41:18 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/09 17:01:51 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	modif_tmp(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '+' && var[i + 1] == '\0')
		{
			ft_strtrim(var, "+");
			break ;
		}
		i++;
	}
}

int	compare_env_entries(const t_env *entry1, const t_env *entry2)
{
	return (ft_strcmp(entry1->name, entry2->name));
}

void	bubble_sort_env_entries(t_env_buf *env)
{
	size_t	n;
	int		swapped;
	size_t	i;
	t_env	temp;

	n = env->nbelem;
	swapped = 1;
	i = 1;
	while (swapped)
	{
		swapped = 0;
		i = 1;
		while (i < n)
		{
			if (compare_env_entries(&(env->buf[i - 1]), &(env->buf[i])) > 0)
			{
				temp = env->buf[i - 1];
				env->buf[i - 1] = env->buf[i];
				env->buf[i] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}
