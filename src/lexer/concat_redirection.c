/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:47:44 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 19:12:19 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	can_concat(t_list_lexer *item)
{
	int	tok;

	tok = item->content->token;
	if (tok >= LS_WORD && tok <= LS_DQUOTE)
		return (1);
	return (0);
}

/**
 * Check if this token is a redirection and can be concatened
 *
 * @param data
 * @return 1 if true, 0 else
 */
static int	is_concat(t_list_lexer *data)
{
	int		tok;
	char	*value;

	tok = data->content->token;
	value = data->content->value;
	if (tok < LS_REDIRECT_RIGHT || tok > LS_HEREDOC)
		return (1);
	else if (tok == LS_REDIRECT_RIGHT && value[1])
		return (1);
	else if (tok == LS_REDIRECT_LEFT && value[1])
		return (1);
	else if (tok == LS_AREDIRECT_RIGHT && value[2])
		return (1);
	else if (tok == LS_HEREDOC && value[2])
		return (1);
	return (0);
}

static void	concat_if_possible(t_list_lexer *datas)
{
	t_list_lexer	*next;
	char			*tmp;

	if (is_concat(datas))
		return ;
	next = datas->next;
	while (next && next->content->token == LS_SEPARATOR)
		next = next->next;
	if (next && can_concat(next))
	{
		tmp = ft_strcat(datas->content->value, next->content->value);
		if (!tmp)
			msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
		free(datas->content->value);
		datas->content->value = tmp;
		tmp = (void *)datas->next;
		datas->next = next->next;
		next->next = NULL;
		ft_lstclear((void *)tmp, (void (*)(void *))msh_lexer_free_data);
	}
	else
	{
		msh_io_print_error(E_INVALID_PROMPT, datas->content->at);
		msh_glob_get()->lexer.lexer.state = LS_PARSE_ERROR;
	}
}

void	concat_redirection(t_list_lexer *datas)
{
	if (ft_lstsize(datas) < 2)
		return ;
	while (datas && msh_glob_get()->lexer.lexer.state != LS_PARSE_ERROR)
	{
		concat_if_possible(datas);
		datas = datas->next;
	}
}
