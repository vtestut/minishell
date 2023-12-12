/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer_second_pass_concat.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:31:51 by pierre            #+#    #+#             */
/*   Updated: 2023/11/19 18:31:51 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	can_concat(t_list_lexer *item)
{
	t_msh_lexer_data	*d;

	d = item->content;
	if (d->token >= LS_WORD
		&& d->token < LS_REDIRECT_RIGHT
		&& d->token != LS_SEPARATOR)
		return (1);
	else
		return (0);
}

static void	concat_lst(t_list_lexer **current, t_list_lexer *last)
{
	t_msh_lexer_data	*c;
	t_msh_lexer_data	*l;
	char				*nstr;

	if (!can_concat(last) || !can_concat(*current))
		return ;
	c = (*current)->content;
	l = last->content;
	nstr = ft_strcat(l->value, c->value);
	free(l->value);
	l->value = nstr;
	last->next = (*current)->next;
	(*current)->next = NULL;
	ft_lstclear(*current, (void (*)(void *))msh_lexer_free_data);
	*current = last;
}

void	msh_lexer_second_pass_concat(t_list_lexer *datas)
{
	t_list_lexer				*last;

	if (ft_lstsize(datas) < 2)
		return ;
	last = datas;
	datas = datas->next;
	while (datas)
	{
		concat_lst(&datas, last);
		last = datas;
		datas = datas->next;
	}
}
