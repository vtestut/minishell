/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:34:32 by vtestut           #+#    #+#             */
/*   Updated: 2023/11/29 16:38:02 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define SUBSITUTE_BEG_SYM '$'
# define SUBSTITUE_END_SYMS " $\n\t\v\f\r\"'+-*/%&|^<>=(){}[];:!?~#"
# define ENV_SPLIT_SYMS " \t\n\r\v\f"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include "types.h"
# include "glob.h"

/** msh_env_init
 * 
 * Store in a global structure buffer, the name and the value of each envp var
 * 
 * @param argc 
 * @param argv 
 * @param envp 
 */
void		msh_env_init(int argc, char **argv, char **envp);

/** msh_env_exit
 * 
 * Free global structure environment buffer and its variables 
 */
void		msh_env_exit(void);

/** msh_env_modif
 * Apply moidification to the value of a variable.
 * Or call msh_env_modif_aux if no value was found with param 'name'
 * 
 * @param name 		name of value we try to modify or create
 * @param new_value	content of new value
 */
void		msh_env_modif(const char *name, const char *new_value);

/** msh_env_delete
 * 
 * @param name	name ot the value to be deleted 
 */
void		msh_env_delete(const char *name);

/**
 * Get the value of the given environment variable
 * 
 * @param name	the name of the environment variable
 * @param var_notation	If true the name use bash variable
 * notation ($[name]) else use [name]
 * 
 * @return the value or an empty string (not a null one)
*/
const char	*msh_env_get(const char *name, int var_notation);

/**
 * Copy str and replace all environment variables by their values
 * or an empty string if none found
 * 
 * @param str	the token to substitute
 * @param split	the split of the token, do not split if NULL
 * 
 * @return		the new string or NULL on failure
*/
char		*msh_env_substitute_all(const char *str, char ***split);

/**
 * Return the environment variables as a NULL terminated array, ready to be
 * used by execve
 *
 * @return	The environment array or NULL on failure
 */
char		**msh_env_get_envp(void);

#endif