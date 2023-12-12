/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:33:59 by vtestut           #+#    #+#             */
/*   Updated: 2023/06/17 17:45:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/glob.h"
#include "env.h"

//strcmp doit ignore minuscule et majuscule
//voir diff entre PATH eet path dans bash

/*	msh_env_delete_aux
*	delete and update the global structure array 
*/
static void	msh_env_delete_aux(const char *name)
{
	t_msh_glob	*glob;
	size_t		i;

	glob = msh_glob_get();
	i = 0;
	while (i < glob->env.nbelem)
	{
		if (ft_strcmp(glob->env.buf[i].name, name) == 0)
		{
			free(glob->env.buf[i].name);
			free(glob->env.buf[i].value);
			glob->env.nbelem--;
			break ;
		}
		i++;
	}
	while (i < glob->env.nbelem)
	{
		glob->env.buf[i] = glob->env.buf[i + 1];
		i++;
	}
	glob->env.buf = realloc(glob->env.buf, glob->env.nbelem * sizeof(t_env));
}

/*	msh_env_delete
*	Check if the variable we want to delete exist
*	If not, return. Else, call msh_delete_aux
*/
void	msh_env_delete(const char *name)
{
	t_msh_glob	*glob;
	size_t		i;
	size_t		check;

	glob = msh_glob_get();
	i = 0;
	check = 0;
	while (i < glob->env.nbelem)
	{
		if (ft_strcmp(glob->env.buf[i].name, name) != 0)
			check++;
		i++;
	}
	if (i == check)
		return ;
	msh_env_delete_aux(name);
}
