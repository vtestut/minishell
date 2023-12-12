/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:16:01 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/15 17:37:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

const char	*msh_env_get(const char *name, int var_notation)
{
	t_env_buf	*env;
	size_t		i;

	if (!ft_strlen(name))
		return ("");
	else if (!ft_strcmp(name + var_notation, "?"))
		return (ft_itoa(msh_glob_get()->exec.exit_status));
	env = &(msh_glob_get()->env);
	i = 0;
	while (i < env->nbelem)
	{
		if (!ft_strcmp(env->buf[i].name, name + (var_notation != 0)))
			return (env->buf[i].value);
		++i;
	}
	return ("");
}
