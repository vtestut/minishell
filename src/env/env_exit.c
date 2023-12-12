/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:29:04 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/23 17:19:42 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	msh_env_exit(void)
{
	size_t		i;
	t_msh_glob	*glob;

	glob = msh_glob_get();
	if (glob->env.buf != NULL)
	{
		i = 0;
		while (i < glob->env.nbelem)
		{
			if (glob->env.buf[i].name)
				free(glob->env.buf[i].name);
			if (glob->env.buf[i].value)
				free(glob->env.buf[i].value);
			i++;
		}
		if (glob->env.buf)
			free(glob->env.buf);
	}
}
