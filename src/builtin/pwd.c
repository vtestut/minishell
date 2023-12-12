/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:01:24 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/09 14:41:56 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	pwd_builtin(char **args)
{
	char	buf[PATH_MAX];
	char	*cwd;

	(void)args;
	cwd = getcwd(buf, PATH_MAX);
	if (cwd)
	{
		ft_putstrfd(cwd, STDOUT_FILENO);
		ft_putstrfd("\n", STDOUT_FILENO);
		return (0);
	}
	errormsg_cmd("pwd", NULL, strerror(errno), errno);
	return (1);
}
