/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:01:39 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/09 14:42:00 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	unset_builtin(char **args)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	while (args[i])
	{
		if (!valid_env_name(args[i]) || ft_strchr(args[i], '=') != NULL)
		{
			errormsg_cmd("unset", args[i], "not a valid identifier", false);
			ret = 1;
		}
		else
			msh_env_delete(args[i]);
		i++;
	}
	return (ret);
}
