/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_io_print_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:24:14 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/09 17:50:13 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include <unistd.h>
#include <stdio.h>

void	msh_io_print_error(int error, char *at)
{
	char	*err;

	err = msh_glob_get()->errors[error];
	write(2, "minishell: ", 11);
	write(2, err, ft_strlen(err));
	if (at)
	{
		write(2, " at: ", 4);
		write(2, at, ft_strlen(at));
		write(2, "\n", 1);
	}
}
