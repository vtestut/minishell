/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:09:32 by pducloux          #+#    #+#             */
/*   Updated: 2023/06/30 21:49:56 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	msh_init_init(int argc, char **argv, char **envp)
{
	msh_io_init(argc, argv, envp);
	msh_error_init(argc, argv, envp);
	msh_env_init(argc, argv, envp);
	msh_lexer_init(argc, argv, envp);
	exec_init(argc, argv, envp);
}
