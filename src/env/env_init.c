/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:11:44 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/09 21:20:50 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"
#include "env.h"
#include "init.h"

/*  msh_env_init_aux
*   Store the name and value of each envronment variable in a buffer structure
*/
static void	msh_env_init_aux(char *sep, char **envp, size_t i)
{
	t_msh_glob	*glob;
	size_t		name_len;

	glob = msh_glob_get();
	name_len = sep - envp[i];
	glob->env.buf[i].name = malloc((name_len + 1) * sizeof(char));
	if (glob->env.buf[i].name == NULL)
		msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
	glob->env.buf[i].value = malloc((ft_strlen(sep + 1) + 1) * sizeof(char));
	if (glob->env.buf[i].value == NULL)
	{
		free(glob->env.buf[i].name);
		msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
	}
	ft_strncpy(glob->env.buf[i].name, envp[i], name_len);
	glob->env.buf[i].name[name_len] = '\0';
	if (ft_strcmp(glob->env.buf[i].name, "SHLVL") == 0)
	{
		ft_strcpy(glob->env.buf[i].value, sep + 1);
		glob->env.buf[i].value[0]++;
		return ;
	}
	ft_strcpy(glob->env.buf[i].value, sep + 1);
}

/*  msh_env_init
*   Get the number of environment variables 
*	and malloc a t_env structure array of this number
*/
void	msh_env_init(int argc, char **argv, char **envp)
{
	t_msh_glob	*glob;
	size_t		count;
	size_t		i;
	char		*sep;

	(void)argc;
	(void)argv;
	glob = msh_glob_get();
	ft_memset(&(glob->env), 0, sizeof(t_env));
	count = 0;
	while (envp[count] != NULL && envp[count][0] != '\0')
		count++;
	glob->env.nbelem = count;
	glob->env.buf = malloc(count * sizeof(t_env));
	if (glob->env.buf == NULL)
		msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
	i = 0;
	while (i < count)
	{
		sep = ft_strchr(envp[i++], '=');
		if (sep != NULL)
			msh_env_init_aux(sep, envp, i - 1);
	}
}
