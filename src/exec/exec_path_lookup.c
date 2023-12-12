/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path_lookup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:45:31 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 14:31:41 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	is_path_absolute(const char *path)
{
	return (path[0] == '/');
}

static int	is_path_relative(const char *path)
{
	if (path[0] != '.')
		return (0);
	return (path[1] == '/' || path[1] == '.');
}

static int	do_path_absolute(const char *binary, char **pathstr)
{
	if (access(binary, F_OK))
		return (EC_COMMAND_NOT_FOUND);
	else if (access(binary, X_OK))
		return (EC_PERMISSION_DENIED);
	*pathstr = ft_strdup(binary);
	return (0);
}

static int	do_path_relative(const char *binary, char **pathstr)
{
	char	*tmp;
	char	path[256];

	tmp = getcwd(path, 256);
	if (!tmp)
		return (EC_COMMAND_NOT_FOUND);
	tmp = ft_strcat(path, "/");
	*pathstr = tmp;
	tmp = ft_strcat(*pathstr, binary);
	free(*pathstr);
	*pathstr = tmp;
	if (!tmp)
		return (134);
	if (access(tmp, F_OK))
		return (free(tmp), EC_COMMAND_NOT_FOUND);
	else if (access(tmp, X_OK))
		return (free(tmp), EC_PERMISSION_DENIED);
	return (0);
}

int	exec_path_lookup(char *binary, char **pathstr)
{
	char	**bindir;
	size_t	i;
	int		code;

	if (!binary)
		return (EC_COMMAND_NOT_FOUND);
	else if (is_path_absolute(binary))
		return (do_path_absolute(binary, pathstr));
	else if (is_path_relative(binary))
		return (do_path_relative(binary, pathstr));
	bindir = ft_split(msh_env_get("PATH", 0), ':');
	if (!bindir)
		return (EC_COMMAND_NOT_FOUND);
	i = 0;
	code = 127;
	while (bindir[i] && code == 127)
		code = check_path(bindir[i++], binary, pathstr);
	free_split(bindir);
	if (code == 134)
		msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
	return (code * !(*pathstr));
}
