/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:30:43 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/06 18:35:34 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*create_path(const char *bindir, const char *binary)
{
	char	*path;
	char	*tmp;

	if (bindir[ft_strlen(bindir) - 1] != '/')
		tmp = ft_strcat(bindir, "/");
	else
		tmp = ft_strdup(bindir);
	if (!tmp)
		return (NULL);
	path = ft_strcat(tmp, binary);
	free(tmp);
	if (!path)
		return (NULL);
	return (path);
}

int	check_path(char *bindir, char *binary, char **pathstr)
{
	char	*path;

	path = create_path(bindir, binary);
	if (!path)
		return (134);
	if (access(path, F_OK))
	{
		free(path);
		return (127);
	}
	if (!access(path, X_OK))
	{
		*pathstr = path;
		return (0);
	}
	else
	{
		free(path);
		return (126);
	}
}
