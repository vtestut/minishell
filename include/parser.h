/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 00:43:21 by pierre            #+#    #+#             */
/*   Updated: 2023/11/29 14:40:09 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include "ft_list.h"
# include "ft_btree.h"
# include "types.h"
# include "utils.h"

/**
 * Initialization function for the parser module
 * 
 * @param argc
 * @param argv
 * @param env
*/
void			msh_parser_init(int argc, char **argv, char **env);

/**
 * Exit function for the parser module
*/
void			msh_parser_exit(void);

/**
 * Parse the lexer
*/
void			msh_parser_parse(void);

/**
 * Get the state of the parser
*/
int				msh_parser_state(void);

/**
 * Check if the token is a command
 * 
 * @param token The lexer token
*/
int				msh_parser_token_is_command(int token);

t_ft_btree_node	*create_command(t_list_lexer **lst);

#endif
