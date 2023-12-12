/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:32:37 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/09 16:43:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include "ft_stdlib.h"
# include "libft.h"
# include "env.h"
# include "ft_ctype.h"
# include "ft_string.h"
# include "error.h"
# include "types.h"
# include "init.h"

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

/**
 * Echo builtin
 * 
 * @param args Arguments
 *
*/
int		echo_builtin(char **args);

/**
 * Change $PWD's value if path exists
 * and is a folder
*/
int		cd_builtin(char **args);

/**
 * Display $PWD's value
*/
int		pwd_builtin(char **args);

/**
 * Create or update an environment variable
*/
int		export_builtin(char **args);

/**
 * Unset (delete) an environment variable
*/
int		unset_builtin(char **args);

/**
 * Display all environment variables
*/
int		env_builtin(char **args);

/**
 * Exit the shell
*/
//int	exit_shell(char **args);

int		exit_builtin(char **args);

bool	valid_env_name(char *var);

/**
 * Check if a command is a builtin, 
 * if true return the builtin function, else return NULL
 *
 * @return The builtin function or NULL if not a builtin
 */
int		(*is_builtin(char *cmd))(char **);

void	modif_tmp(char *var);

int		compare_env_entries(const t_env *entry1, const t_env *entry2);

void	bubble_sort_env_entries(t_env_buf *env);

#endif