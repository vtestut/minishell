/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:12:37 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 20:34:44 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "types.h"
# include "utils.h"
# include "init.h"
# include "ft_string.h"
# include "ft_list.h"

/**
 * Initialization function for the lexer module
 * 
 * @param argc
 * @param argv
 * @param env
*/
void				msh_lexer_init(int argc, char **argv, char **env);

void				init_fsm_4(int table[LS_FINISHED + 1][LS_FINISHED + 1]);

void				init_fsm_5(int table[LS_FINISHED + 1][LS_FINISHED + 1]);

void				init_fsm_6(int table[LS_FINISHED + 1][LS_FINISHED + 1]);

void				init_fsm_7(int table[LS_FINISHED + 1][LS_FINISHED + 1]);

void				init_fsm_8(int table[LS_FINISHED + 1][LS_FINISHED + 1]);

/**
 * Initialization function for the finite state machine
 * 
 * @param table		the address of the state transition table
*/
void				msh_lexer_init_fsm(
						int table[LS_FINISHED + 1][LS_FINISHED + 1]);

/**
 * Exit function for the lexer module
*/
void				msh_lexer_exit(void);

/**
 * Parse the given input into a list of tokens
 * 
 * @param input		the input to parse
 * 
 * @return a list of token or NULL on failure 
*/
t_msh_lexer			*msh_lexer_parse(char *input);

/**
 * Second pass of the lexer, do in order:
 * 	-	substitute env variable
 * 	-	concatenate quotes
 * 	-	remove separators
 * 
 * @param datas		the lexer datas
*/
void				msh_lexer_second_pass(t_list_lexer *datas);

/**
 * Concatenate some datas, eg: "ca"t => cat
*/
void				msh_lexer_second_pass_concat(t_list_lexer *datas);

/**
 * @brief Concatenate redirections, eg: > filename => >filename
 * 
 * @param datas 
 */
void				concat_redirection(t_list_lexer *datas);

/**
 * Return if the lexer is ok
*/
int					msh_lexer_is_ok(void);

//##########################################
//				LEXER UTILS
//##########################################

/**
 * Check if the given token is a redirection
 * 
 * @param token		the token to check
 * 
 * @return 1 if the token is a redirection, 0 otherwise
*/
int					lexer_token_is_redirection(int token);

/**
 * Check if the given token is part of a command
 * 
 * @param token		the token to check
 * 
 * @return 1 if the token is part of a command, 0 otherwise
*/
int					lexer_token_is_command(int token);

t_msh_lexer_data	*create_lexer_data(int token, char *value, const char *at);

void				substitute_add_tokens(t_list_lexer *datas, char **split);

void				remove_quotes(t_list_lexer **tokens);

void				substitute_env(t_list_lexer *datas);

#endif