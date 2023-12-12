/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_io_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:13:42 by pducloux          #+#    #+#             */
/*   Updated: 2023/06/16 14:43:09 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include <stdio.h>
#include "readline/readline.h"
#include "readline/history.h"

void	msh_io_exit(void)
{
	rl_clear_history();
	rl_cleanup_after_signal();
}
