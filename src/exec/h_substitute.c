/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_substitute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:48:35 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/09 20:48:42 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

size_t	substitute_that(char **new, size_t begin, size_t end)
{
	char		*name;
	char		*tmp;
	const char	*value;
	size_t		namelen;
	size_t		valuelen;

	if (begin == end - 1)
		return (begin + 1);
	namelen = end - begin;
	name = ft_strndup(*new + begin, namelen);
	if (!name)
		return (msh_init_exit_error(E_OUT_OF_MEMORY, NULL), 0);
	value = msh_env_get(name, 1);
	free(name);
	valuelen = ft_strlen(value);
	tmp = ft_strreplacen(*new, begin, namelen, value);
	if (!tmp)
		return (msh_init_exit_error(E_OUT_OF_MEMORY, NULL), 0);
	free(*new);
	*new = tmp;
	return (begin + valuelen);
}

char	*h_substitute(char *str)
{
	char				*iter[2];
	size_t				siter;

	if (!str)
		return (NULL);
	ft_memset(iter, 0, sizeof(iter));
	iter[0] = ft_strchr(str, SUBSITUTE_BEG_SYM);
	while (iter[0])
	{
		iter[1] = ft_strchr1(iter[0] + 1, SUBSTITUE_END_SYMS);
		if (!ft_strncmp(iter[0], "$?", 2))
			iter[1] = iter[0] + 2;
		else if (!iter[1])
			iter[1] = iter[0] + ft_strlen(iter[0]);
		siter = substitute_that(&str, iter[0] - str, iter[1] - str);
		if (*(str + siter))
			iter[0] = ft_strchr(str + siter, SUBSITUTE_BEG_SYM);
		else
			iter[0] = NULL;
	}
	return (str);
}
