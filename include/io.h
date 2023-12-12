/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:29:39 by pducloux          #+#    #+#             */
/*   Updated: 2023/06/16 13:08:46 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include "ft_string.h"
# include "glob.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/**
 * Prompt the user for a new command
 * 
 * @return a new command or NULL on failure
*/
char	*msh_io_read_input(void);

/**
 * Print an error message to the prompt
 * 
 * @param msg		the message
*/
void	msh_io_print_error(int error, char *at);

void	msh_io_init(int argc, char **argv, char **env);

void	msh_io_exit(void);

#endif