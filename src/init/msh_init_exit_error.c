/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init_exit_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:17:23 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/29 16:30:16 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "io.h"

void	msh_init_exit_error(int code, char *at)
{
	msh_io_print_error(code, at);
	msh_init_exit(code, NULL);
}
