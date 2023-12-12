/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_get_envp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:17:58 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/09 17:18:22 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*env2str(t_env envvar)
{
	char	*str;
	char	*tmp;

	str = ft_strcat(envvar.name, "=");
	if (!str)
		return (NULL);
	tmp = str;
	str = ft_strcat(tmp, envvar.value);
	return (free(tmp), str);
}

char	**msh_env_get_envp(void)
{
	t_env_buf	*envbuff;
	char		**envp;
	size_t		envlen;
	size_t		i;

	envbuff = &(msh_glob_get()->env);
	envlen = envbuff->nbelem;
	envp = malloc(sizeof(char *) * (envlen + 1));
	if (!envp)
		return (NULL);
	envp[envlen] = NULL;
	i = 0;
	while (i < envlen)
	{
		envp[i] = env2str(envbuff->buf[i]);
		i++;
	}
	return (envp);
}
