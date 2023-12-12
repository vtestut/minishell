/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_error_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:42:38 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/06 18:14:29 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "types.h"

int	error_msg(char *str1, char *str2, char *str3, int erno)
{
	ft_putstr_fd("minishell error: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putendl_fd(str3, 2);
	return (erno);
}

int	errormsg_cmd(char *cmd, char *arg, char *strerror, int erno)
{
	ft_putstr_fd("msh: ", 2);
	ft_putstr_fd(cmd, 2);
	if (arg != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg, 2);
	}
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror, 2);
	return (erno);
}

static void	error_msg_01(char **errors)
{
	errors[E_OUT_OF_MEMORY] = "Out of memory";
	errors[E_INVALID_PROMPT] = "Invalid Prompt";
	errors[E_INVALID_REDIRECTION] = "Invalid redirection";
	errors[E_COMMAND_NOT_FOUND] = "Command not found";
	errors[E_PERMISSION_DENIED] = "Permission denied";
	errors[E_SIGNAL] = "Could not create signal";
	errors[E_UN_TEST] = "un test";
}

void	msh_error_init(int argc, char **argv, char **env)
{
	char	**msg;

	(void)argc;
	(void)argv;
	(void)env;
	msg = msh_glob_get()->errors;
	error_msg_01(msg);
}
