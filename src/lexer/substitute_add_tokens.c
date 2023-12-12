/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_add_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:37:11 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/06 18:51:42 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	inside_loop(char ***iter, t_list_lexer *datas, t_list *new_list)
{
	t_msh_lexer_data	*new_data;

	new_data = create_lexer_data(LS_WORD, ft_strdup(**iter),
			datas->content->at);
	if (!(*new_list).lexer)
		ft_lstaddback(new_list, ft_lstnew(create_lexer_data(LS_SEPARATOR,
					ft_strdup(" "), datas->content->at)));
	ft_lstaddback(new_list, ft_lstnew(new_data));
	ft_lstaddback(new_list, ft_lstnew(create_lexer_data(LS_SEPARATOR,
				ft_strdup(" "), datas->content->at)));
	++(*iter);
}

void	substitute_add_tokens(t_list_lexer *datas, char **split)
{
	t_list				new_list;
	char				**iter;

	if (!(*split) || datas->content->token == LS_DQUOTE)
		return ;
	ft_memset(&new_list, 0, sizeof(t_list));
	iter = split;
	free(datas->content->value);
	datas->content->value = ft_strdup(*iter);
	++iter;
	while (*iter)
		inside_loop(&iter, datas, &new_list);
	iter = (char **)datas->next;
	datas->next = NULL;
	datas->next = new_list.lexer;
	ft_lstlast(datas).lexer->next = (t_list_lexer *)iter;
}
