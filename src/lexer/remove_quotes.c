/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:42:22 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/09 17:11:59 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	inside_loop(t_list_lexer **tokens,
	t_list_lexer **before, t_list_lexer **lst)
{
	t_msh_lexer_data	*d;

	(void)tokens;
	(void)before;
	(void)lst;
	d = (*lst)->content;
	if (d->token == LS_DQUOTE || d->token == LS_SQUOTE)
		ft_strtrim_one(d->value, "'\"");
	*before = *lst;
	if (*lst)
		*lst = (*lst)->next;
}

static int	is_quote(t_list_lexer *lst)
{
	t_msh_lexer_data	*d;

	if (!lst)
		return (0);
	d = lst->content;
	return (d->token == LS_DQUOTE || d->token == LS_SQUOTE);
}

void	remove_quotes(t_list_lexer **tokens)
{
	t_list_lexer		*before;
	t_list_lexer		*lst;

	before = NULL;
	lst = *tokens;
	while (lst)
		inside_loop(tokens, &before, &lst);
	lst = *tokens;
	before = NULL;
	if (!is_quote(lst))
		return ;
	while (lst && is_quote(lst) && !ft_strlen(lst->content->value))
	{
		before = lst;
		lst = lst->next;
	}
	if (before)
		before->next = NULL;
	ft_lstclear(*tokens, (void (*)(void *))msh_lexer_free_data);
	*tokens = lst;
}
