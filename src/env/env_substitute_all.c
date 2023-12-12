/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_substitute_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:18:32 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/29 16:51:33 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "init.h"
#include "io.h"

size_t	substitute(char **new, size_t begin, size_t end)
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

char	*msh_env_substitute_all(const char *str, char ***split)
{
	char				*new;
	char				*iter[2];
	size_t				siter;

	new = ft_strdup(str);
	if (!new)
		return (msh_init_exit_error(E_OUT_OF_MEMORY, NULL), NULL);
	ft_memset(iter, 0, sizeof(iter));
	iter[0] = ft_strchr(new, SUBSITUTE_BEG_SYM);
	while (iter[0])
	{
		iter[1] = ft_strchr1(iter[0] + 1, SUBSTITUE_END_SYMS);
		if (!ft_strncmp(iter[0], "$?", 2))
			iter[1] = iter[0] + 2;
		else if (!iter[1])
			iter[1] = iter[0] + ft_strlen(iter[0]);
		siter = substitute(&new, iter[0] - new, iter[1] - new);
		if (*(new + siter))
			iter[0] = ft_strchr(new + siter, SUBSITUTE_BEG_SYM);
		else
			iter[0] = NULL;
	}
	*split = ft_splitcs(new, " \t\n\r\v\f");
	return (new);
}
