/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:54:36 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/09 17:36:57 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "ft_stdlib.h"

/*	msh_env_modif_aux
*	If no value found with 'name'
*	Create a new value and increment 'nbelem'
*/
static void	msh_env_modif_aux(const char *name, const char *nv)
{
	t_msh_glob	*glob;
	size_t		i;

	glob = msh_glob_get();
	i = glob->env.nbelem;
	glob->env.buf = ft_realloc(glob->env.buf, i * sizeof(t_env),
			(i + 1) * sizeof(t_env));
	glob->env.buf[i].name = malloc((ft_strlen(name) + 1) * sizeof(char));
	if (glob->env.buf[i].name == NULL)
		return ;
	glob->env.buf[i].value = malloc((ft_strlen(nv) + 1) * sizeof(char));
	if (glob->env.buf[i].value == NULL)
		return ;
	ft_strcpy(glob->env.buf[i].name, name);
	ft_strcpy(glob->env.buf[i].value, nv);
	glob->env.nbelem++;
}

void	msh_env_modif(const char *name, const char *nv)
{
	t_msh_glob	*glob;
	size_t		i;

	glob = msh_glob_get();
	i = 0;
	while (i < glob->env.nbelem)
	{
		if (ft_strcmp(glob->env.buf[i].name, name) == 0)
		{
			free(glob->env.buf[i].value);
			glob->env.buf[i].value = malloc((ft_strlen(nv) + 1) * sizeof(char));
			ft_strcpy(glob->env.buf[i].value, nv);
			return ;
		}
		i++;
	}
	msh_env_modif_aux(name, nv);
}
