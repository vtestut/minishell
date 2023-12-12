/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:52 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/04 16:14:20 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <sys/types.h>
# include "types/defines.h"

/*******************
 * FORWARD DECLARATIONS
 *******************/

//typedef struct s_ft_btree_node	t_ft_btree_node;

//typedef union u_list			t_list;

/*******************
 * ENVIRONMENT
 *******************/

/**
 * Represent an environment variable
 *
 * @var name 	the name of the variable
 * @var value	the value of the variable
 */
typedef struct s_env
{
	char	*name;
	char	*value;
}									t_env;

/**
 * Contain all environment variables
 *
 * @var buf		the buffer of environment variables
 * @var nbelem	the number of environment variables
 */
typedef struct s_env_buf {
	t_env	*buf;
	size_t	nbelem;
}									t_env_buf;

typedef t_msh_lexer_state			t_msh_lexer_token;

/**
 * @struct	s_msh_lexer_data
 * @brief	this structure represent a token
 *
 * @var		s_msh_lexer_data::token
 * @brief	token flags
 *
 * @var		s_msh_lexer_data::value
 * @brief	the actual value of the token
 */
typedef struct s_msh_lexer_data {
	t_msh_lexer_token	token;
	char				*value;
	char				*at;
}									t_msh_lexer_data;

/**
 * Is used to provide more information about underlying types than t_list, a
 * cast to (t_lst *) is required to use ft_list's functions
 */
typedef struct s_list_lexer {
	t_msh_lexer_data	*content;
	struct s_list_lexer	*next;
}									t_list_lexer;

/**
 * @struct	s_msh_lexer
 * @brief	store the lexer tokens and states
 *
 * @var		s_msh_lexer::states
 * @brief	a linked list containing the states of the lexer
 *
 * @var		s_msh_lexer::datas
 * @brief	a linked list containing the tokens of the lexer
 */
typedef struct s_msh_lexer {
	t_msh_lexer_state	state;
	t_list_lexer		*datas;
}									t_msh_lexer;

/*******************
 * PARSER
 *******************/

enum e_msh_parser_state {
	PS_ERROR,
	PS_OK
};

enum e_msh_parser_priority {
	PP_COMMAND,
	PP_PIPE
};

/*******************
 * EXECUTION
 *******************/

typedef enum e_cmd_flags {
	E_CMD_FIRST		= 1,
	E_CMD_BETWEEN	= E_CMD_FIRST	<< 1,
	E_CMD_LAST		= E_CMD_BETWEEN	<< 1,
}									t_cmd_flags;

/**
* Used instead of t_list to provide information about underlying data types
*/
typedef struct s_list_redirect {
	struct s_redir_data {
		t_msh_lexer_token	type;
		char				*file;
	}						*content;
	struct s_list_redirect	*next;
}									t_list_redirect;

// Used instead of t_list to provide information about underlying data types
typedef struct s_list_heredoc {
	char					*content;
	struct s_list_heredoc	*next;
}									t_list_heredoc;

/**
* @brief The command info structure.
*
* @var cmd         The command.
* @var command     The command list.
* @var redir       The redirection list.
* @var heredoc     A list of heredoc to perform
* @var heredoc_str	The str containing the heredoc (each heredoc is appended
* 					to the last one)
* @var heredoc_len	The size of the heredoc str.
* @var for_nd      The address of the node using this struct
*                  (is used as an id in case of CTRL-C).
* @var pid         The pid of the process using this struct
*                  (is used to kill current process in case of CTRL-C).
*/
typedef struct s_cmd_info {
	t_list_lexer	*command;
	t_list_redirect	*redir;
	t_list_heredoc	*heredoc;
	t_cmd_flags		cmd_flags;
	int				fdin;
	int				fdout;
	int				pid;
	char			*heredoc_str;
}									t_cmd_info;

/*******************
 * BUILTINS
 *******************/

/*******************
 * HISTORY
 *******************/

/*******************
 * GLOBAL
 *******************/

/**
 * Lexer global data structure
 *
 * @var char_lookup_table	The FSM's symbols lookup table
 * @var fsm_lookup_table	The FSM's states transition lookup table
 * @var lexer				The lexer datas
 */
typedef struct s_glob_lexer {
	int			char_lookup_table[256];
	int			fsm_lookup_table[LS_FINISHED + 1][LS_FINISHED + 1];
	t_msh_lexer	lexer;
}									t_glob_lexer;

/*******************
 * LIBFT CUSTOM TYPES
 *******************/

/**
 * Custom type for ft_list, is used by ft_list family of functions
 *
 * @var	list				Basic list type, provide no typehint
 * @var lexer				Lexer list type (contain tokens)
 * @var redirect			Redirection list type
 * @var heredoc				Heredoc list type
 */
typedef union __attribute((transparent_union)) u_list {
	struct s_list {
		void	*content;
		void	*next;
	}	*list;
	t_list_lexer	*lexer;
	t_list_redirect	*redirect;
	t_list_heredoc	*heredoc;
}									t_list;

typedef enum e_msh_parser_priority	t_ft_btree_node_type;

/**
 * Custom content type for ft_btree
 *
 * @var pcdata	Parser command data
 * @var pdata	Parser data (pipe, &&, ||...)
 * @var command	Execution data for commands
 */
union u_tree_content {
	t_list_lexer		*pcdata;
	char				*pdata;
	t_cmd_info			command;
	char				redirect;
	char				heredoc;
};

/**
 * Custom type for ft_btree, is used by ft_btree family of functions
 *
 * @var type	The type of node
 * @var content	The content of the node
 * @var first	The first child of the node
 * @var second	The second child of the node
 */
typedef struct s_ft_btree_node {
	t_ft_btree_node_type	type;
	union u_tree_content	*content;
	struct s_ft_btree_node	*first;
	struct s_ft_btree_node	*second;
}									t_ft_btree_node;
/**
 * Lexer global data structure
 *
 * @var state				The parser state
 * @var tree				The binary tree
 */
typedef struct s_glob_parser {
	int				state;
	t_ft_btree_node	*tree;
}									t_glob_parser;

/**
 * Execution global data structure
 *
 * @var tree				The binary tree
 * @vsr pipes				The pipes
 */
typedef struct s_glob_exec {
	t_ft_btree_node	*tree;
	int				read_that;
	int				pipes[2];
	pid_t			pid;
	t_exec_state	state;
	int				exit_status;
	int				stdfds_backup[3];
	t_list_heredoc	*current_heredoc;
}									t_glob_exec;

/**
 * Global data structure
 *
 * @var lexer				The lexer global datas
 * @var parser				The parser global datas
 * @var errors				Error lookup table
 * @var	env					Environment global datas
 */
typedef struct s_msh_glob {
	struct s_glob_lexer		lexer;
	struct s_glob_parser	parser;
	struct s_glob_exec		exec;
	char					*errors[256];
	char					*line;
	t_env_buf				env;
	int						sig;
}									t_msh_glob;

#endif