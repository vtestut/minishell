/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:35:18 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/09 20:49:18 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include "types.h"
# include "glob.h"
# include "env.h"
# include "utils.h"
# include "builtin.h"
# include "ft_string.h"
# include "ft_list.h"
# include "ft_btree.h"

/**
 * Initializes the exec module.
 * 
 * @param argc The number of arguments passed to the program.
 * @param argv The arguments passed to the program.
 * @param envp The environment variables.
*/
void			exec_init(int argc, char **argv, char **envp);

/**
 * Exits the exec module.
*/
void			exec_exit(void);

void			msh_exec(void);

/**
 * Create and initialize the command info structure for the given node.
 *
 * @param cmd
 * @return
 */
t_cmd_info		exec_gen_cmdinfo(t_list_lexer *lexdat);

/**
 * Iterate over the command and execute the heredoc.
 * 
 * @param cmd_info  The command info list.
 * @param n         The number of command to execute.
*/
void			exec_store_heredoc(t_cmd_info *cmd_info);

/**
 * @brief Dup heredoc into stdin if needed.
 * 
 * @param cmd 
 * 
 * @return int		0 on success, else the error code will be returned,
 * 					(127 for not found, 126 for permission denied)
 */
int				exec_do_heredoc(t_cmd_info cmd);

/**
 * @brief Execute the redirections of the command.
 * 
 * @param cmd 
 * @return int		0 on success, else the error code will be returned,
 * 					(127 for not found, 126 for permission denied)
 */
int				exec_do_redirect(t_cmd_info cmd);

/**
 * Generate a new tree from the parser's one
 *
 * @param ptree		The parser tree
 *
 * @return A new tree, which have t_lexer_list replaced by t_cmd_info for
 * ease of use
 */
t_ft_btree_node	*exec_gen_tree(t_ft_btree_node *ptree);

/**
 * Search the path for the executable file binary, perform permission checking,
 * if the path is found pathstring will be overwritten
 *
 * @param binary
 * @param pathstr	ptr over a string, is used to return the path
 *
 * @return	0 on success, else the error code will be returned, 
 * 			(127 for not found, 126 for permission denied)
 */
int				exec_path_lookup(char *binary, char **pathstr);

/**
 * Execute a command
 *
 * @param cmd
 */
void			exec_child(t_cmd_info cmd);

/**
 * Execute a builtin
 * @param cmd
 */
void			exec_builtin(t_cmd_info cmd);

/**
 * Execute a builtin without forking (when not in pipe)
 *
 * @param cmd
 */
void			exec_builtin_non_fork(t_cmd_info cmd);

/**
 * Execute a pipe
 * @param nd
 */
void			exec_pipe(t_ft_btree_node **nd);

/**
 * free a tree
 * @param tree_ptr
 */
void			msh_free_tree(t_ft_btree_node *tree_ptr);

void			exec_tree_v2(t_ft_btree_node *tree);

/**
 * @brief Check the existance of a path
 * 
 * @param bindir 
 * @param binary 
 * @param pathstr 
 * @return int 	0 on success, 126 if permission denied, 
 * 				127 if not found, 134 if malloc error
 */
int				check_path(char *bindir, char *binary, char **pathstr);

char			*heredoc_get_prompt(const char *end_symbol);

char			*add_line(char *buff, char **line, const char *prompt);

void			close_all_pipes(void);

char			*h_substitute(char *str);

#endif