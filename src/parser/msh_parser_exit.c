/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:29:01 by pierre            #+#    #+#             */
/*   Updated: 2023/11/23 18:33:19 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "glob.h"
#include "ft_btree.h"
#include "lexer.h"
#include "utils.h"

void	msh_parser_exit(void)
{
	t_glob_parser	*parser;

	parser = &(msh_glob_get()->parser);
	ft_btree_delete_type(parser->tree,
		(void (*)(void *, t_ft_btree_node_type))msh_parser_free_data);
	ft_memset(parser, 0, sizeof(t_glob_parser));
	parser->state = PS_OK;
}
