/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:59:13 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/09 14:41:27 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	env_builtin(char **args)
{
	size_t		i;
	t_env_buf	*tmp;

	tmp = &(msh_glob_get()->env);
	if (args && args[1])
		return (errormsg_cmd("env", NULL, "too many arguments", 2));
	i = 0;
	while (i < tmp->nbelem)
	{
		ft_putstrfd(tmp->buf[i].name, STDOUT_FILENO);
		ft_putstrfd("=", STDOUT_FILENO);
		ft_putstrfd((tmp->buf[i].value), STDOUT_FILENO);
		ft_putstrfd("\n", STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
