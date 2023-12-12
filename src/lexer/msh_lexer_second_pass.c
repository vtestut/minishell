/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer_second_pass.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:09:34 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/09 20:34:34 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "error.h"
#include "init.h"

/**
 * Remove all separators
*/
static void	remove_separators(t_list_lexer *datas)
{
	t_list_lexer				*before;
	t_list_lexer				*tmp;
	t_msh_lexer_data			*d;

	before = NULL;
	while (datas)
	{
		d = datas->content;
		if (d->token == LS_SEPARATOR && before)
		{
			tmp = datas;
			datas = datas->next;
			before->next = datas;
			tmp->next = NULL;
			ft_lstclear(tmp, (void (*)(void *))msh_lexer_free_data);
		}
		else
		{
			before = datas;
			datas = datas->next;
		}
	}
}

/**
 * Substitute environment variables with values
*/
void	substitute_env(t_list_lexer *datas)
{
	t_msh_lexer_data	*d;
	char				*tmp;
	char				**split;

	while (datas)
	{
		d = datas->content;
		if (d->token != LS_SQUOTE)
		{
			tmp = msh_env_substitute_all(d->value, &split);
			free(d->value);
			d->value = tmp;
			substitute_add_tokens(datas, split);
			free_split(split);
		}
		datas = datas->next;
	}
}

static void	validate_pipes(t_list_lexer *lst)
{
	while (lst && lst->next)
	{
		if (lst->content->token == LS_PIPE
			&& lst->next->content->token == LS_PIPE)
		{
			msh_glob_get()->lexer.lexer.state = LS_PARSE_ERROR;
			msh_io_print_error(E_INVALID_PROMPT, lst->next->content->at);
			return ;
		}
		lst = lst->next;
	}
}

void	msh_lexer_second_pass(t_list_lexer *datas)
{
	t_list_lexer	**tmp;

	if (msh_glob_get()->lexer.lexer.state == LS_PARSE_ERROR)
		return ;
	tmp = &(msh_glob_get()->lexer.lexer.datas);
	substitute_env(datas);
	remove_quotes(tmp);
	if (!*tmp)
	{
		printf("error: Command not found\n");
		msh_glob_get()->lexer.lexer.state = LS_PARSE_ERROR;
		return ;
	}
	msh_lexer_second_pass_concat(datas);
	remove_separators(datas);
	concat_redirection(datas);
	validate_pipes(datas);
	if (!datas)
		msh_glob_get()->lexer.lexer.state = LS_PARSE_ERROR;
}
