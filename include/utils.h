/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:56:41 by pierre            #+#    #+#             */
/*   Updated: 2023/11/23 01:56:41 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"
# include "ft_string.h"
# include "ft_list.h"
# include "ft_btree.h"

/**
 * Free a t_msh_lexer_data element
*/
void				msh_lexer_free_data(t_msh_lexer_data *d);

/**
 * Deep copy a t_msh_lexer_data element
*/
t_msh_lexer_data	*msh_lexer_data_dup(t_msh_lexer_data *data);

/**
 * Free a t_msh_parser_data element
 * @param content
 */
void				msh_parser_free_data(
						union u_tree_content *content,
						t_ft_btree_node_type type);

void				msh_free_cmdinfo(
						union u_tree_content *content,
						t_ft_btree_node_type type);

void				free_t_list_heredoc(char *content);

/**
 * Transform a t_list_lexer into a char **, the last element of the array is NULL
 *
 * @param cmdlst
 * @return	An array of char * or NULL if malloc failed
 */
char				**lst2split(t_list_lexer *cmdlst);

void				free_split(char **arr);

void				*tree_dup(void *content, t_ft_btree_node_type type);

void				tree_free(void *content, t_ft_btree_node_type type);

#endif