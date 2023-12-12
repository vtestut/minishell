/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:09:49 by pducloux          #+#    #+#             */
/*   Updated: 2023/11/15 16:07:32 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	msh_init_exit(int code, char *msg)
{
	(void)code;
	(void)msg;
	msh_error_exit();
	msh_lexer_exit();
	msh_parser_exit();
	msh_io_exit();
	msh_env_exit();
	exec_exit();
	if (msh_glob_get()->line)
		free(msh_glob_get()->line);
	if (msg)
		write((code > 0) + 1, msg, ft_strlen(msg));
	exit(code);
}
