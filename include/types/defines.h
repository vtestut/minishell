/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:27 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/06 18:15:27 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/**
 * The error codes
 */
enum e_msh_error {
	E_OUT_OF_MEMORY = 134,
	E_INVALID_PROMPT,
	E_INVALID_PIPE,
	E_INVALID_REDIRECTION,
	E_PERMISSION_DENIED = 126,
	E_COMMAND_NOT_FOUND = 127,
	E_SIGNAL,
	E_UN_TEST
};

enum e_msh_exit_code {
	EC_SUCCESS = 0,
	EC_FAILURE = 1,
	EC_PERMISSION_DENIED = 126,
	EC_COMMAND_NOT_FOUND = 127,
	EC_OUT_OF_MEMORY = 137,
};

/**
 * @enum	e_msh_lexer_state
 * @brief	Enumeration of the different lexer states
 */
typedef enum e_msh_lexer_state
{
	LS_START,
	LS_PARSING,
	LS_WORD,
	LS_NUMBER,
	LS_SEPARATOR,
	LS_SQUOTE,
	LS_DQUOTE,
	LS_REDIRECT_RIGHT,
	LS_AREDIRECT_RIGHT,
	LS_REDIRECT_LEFT,
	LS_HEREDOC,
	LS_PIPE,
	LS_PARSE_ERROR,
	LS_FINISHED
}	t_msh_lexer_state;

typedef enum e_exec_state {
	ES_PENDING	= 0,
	ES_RUNNING	= 1 << 0,
	ES_HEREDOC	= 1 << 1,
	ES_STOPPED	= 1 << 2,
	ES_DONE		= 1 << 3,
}	t_exec_state;

#endif
