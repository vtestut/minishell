/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:59:35 by pierre            #+#    #+#             */
/*   Updated: 2023/11/29 14:39:19 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "types.h"
# include "lexer.h"
# include "error.h"
# include "io.h"
# include "exec.h"
# include "parser.h"
# include "env.h"

/**
 * Function to initialize every module at the start of the program
 *
 * @param argc
 * @param argv
 * @param env
 */
void	msh_init_init(int argc, char **argv, char **env);

/**
 * Function to exit each module at the end of the program
 *
 * @param code		the exit code
 * @param msg		the exit message, if NULL none is displayed
 */
void	msh_init_exit(int code, char *msg);

/**
 * Function to exit each module at the end of the program
 * with an error message
 *
 * @param error		the error code
 */
void	msh_init_exit_error(int error, char *at);

#endif