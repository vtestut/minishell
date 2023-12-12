/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:49:55 by pierre            #+#    #+#             */
/*   Updated: 2023/07/28 18:22:12 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"
#include "glob.h"

/**
 *
 * @param lst
 * @return
 */
static t_ft_btree_node	*create_node(t_list_lexer **lst)
{
	t_msh_lexer_data		*data;
	int						prio;
	union u_tree_content	*content;

	if (!*lst)
		return (NULL);
	data = (*lst)->content;
	if (msh_parser_token_is_command(data->token))
		return (create_command(lst));
	prio = data->token - LS_HEREDOC;
	*lst = (*lst)->next;
	content = malloc(sizeof(union u_tree_content));
	ft_memset(content, 0, sizeof(union u_tree_content));
	content->pdata = ft_strdup(data->value);
	return (ft_btree_create(content, prio));
}

/**
 * Recursively parse the tree, in case of error set the parser state to PS_ERROR
 * 
 * @param parser	The parser
 * @param tree		The tree
 * @param lst		The list of tokens
*/
static t_ft_btree_node	*parse(t_glob_parser *parser, t_list_lexer *lst)
{
	t_ft_btree_node	*node;
	t_ft_btree_node	*after;

	if (!lst)
		return (NULL);
	node = create_node(&lst);
	if (!lst)
		return (node);
	after = parse(parser, lst);
	if (!after)
		return (node);
	else if (after->type > node->type)
	{
		after->first = node;
		return (after);
	}
	else
	{
		node->second = after;
		return (node);
	}
}

void	msh_parser_parse(void)
{
	t_list_lexer	*lst;
	t_glob_parser	*parser;

	msh_parser_exit();
	lst = (msh_glob_get()->lexer.lexer.datas);
	parser = &(msh_glob_get()->parser);
	if (msh_glob_get()->lexer.lexer.state == LS_PARSE_ERROR)
		return (parser->state = PS_ERROR, (void)0);
	parser->tree = parse(parser, lst);
	return ((void)0);
}
