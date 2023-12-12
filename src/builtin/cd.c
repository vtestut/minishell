/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:55:45 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/06 16:25:20 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static bool	change_dir(char *path)
{
	char	*ret;
	char	*tmp;
	char	cwd[PATH_MAX];

	ret = NULL;
	if (chdir(path) != 0)
		return (errormsg_cmd("cd", path, strerror(errno), errno), 0);
	ret = getcwd(cwd, PATH_MAX);
	if (!ret)
	{
		errormsg_cmd("cd : error retrieving current directory",
			"getcwd : cannot access parent directories",
			strerror(errno), errno);
		ret = ft_strjoin((char *)msh_env_get("PWD", 0), "/");
		tmp = ret;
		ret = ft_strjoin(tmp, path);
		free(tmp);
	}
	else
		ret = ft_strdup(cwd);
	msh_env_modif("OLDPWD", msh_env_get("PWD", 0));
	msh_env_modif("PWD", ret);
	free(ret);
	return (true);
}

int	cd_builtin(char **args)
{
	char		*path;

	if (!args || !args[1] || ft_isspace(args[1][0])
		|| args[1][0] == '\0' || ft_strncmp(args[1], "--", 3) == 0)
	{
		path = (char *)msh_env_get("HOME", 0);
		if (!path || *path == '\0' || ft_isspace(*path))
			return (errormsg_cmd("cd", NULL, "HOME not set", EXIT_FAILURE));
		return (!change_dir(path));
	}
	if (args[2])
		return (errormsg_cmd("cd", NULL, "too many arguments", EXIT_FAILURE));
	if (ft_strncmp(args[1], "-", 2) == 0)
	{
		path = (char *)msh_env_get("OLDPWD", 0);
		if (ft_strncmp(path, "", 2) == 0)
			return (errormsg_cmd("cd", NULL, "OLDPWD not set", EXIT_FAILURE));
		ft_putendl_fd(path, STDOUT_FILENO);
		return (!change_dir(path));
	}
	return (!change_dir(args[1]));
}
