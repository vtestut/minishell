/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:58:54 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/08 19:53:41 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	no_newline_option(char **args, size_t *i_ptr, int *j_ptr, \
	int *newline_ptr)
{
	*j_ptr = 2;
	while (args[*i_ptr][*j_ptr])
	{
		if (args[*i_ptr][*j_ptr] != 'n')
		{
			*j_ptr = -1;
			break ;
		}
		*j_ptr += 1;
	}
	if (*j_ptr > 0)
	{
		*newline_ptr = 0;
		*i_ptr += 1;
		return (1);
	}
	else
		return (0);
}

int	echo_builtin(char **args)
{
	size_t	i;
	int		j;
	int		newline;

	if (!args[1])
	{
		ft_putchar_fd('\n', 1);
		return (EXIT_SUCCESS);
	}
	newline = 1;
	i = 1;
	while (args[i] && (ft_strncmp(args[i], "-n", 2) == 0))
		if (!no_newline_option(args, &i, &j, &newline))
			break ;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (EXIT_SUCCESS);
}
