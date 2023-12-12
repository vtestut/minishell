/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:40:14 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/11 17:52:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	(*is_builtin(char *cmd))(char **argv)
{
	if (!ft_strcmp(cmd, "echo"))
		return (&echo_builtin);
	else if (!ft_strcmp(cmd, "cd"))
		return (&cd_builtin);
	else if (!ft_strcmp(cmd, "pwd"))
		return (&pwd_builtin);
	else if (!ft_strcmp(cmd, "export"))
		return (&export_builtin);
	else if (!ft_strcmp(cmd, "unset"))
		return (&unset_builtin);
	else if (!ft_strcmp(cmd, "env"))
		return (&env_builtin);
	else if (!ft_strcmp(cmd, "exit"))
		return (&exit_builtin);
	return (NULL);
}
