/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:20:11 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 19:23:01 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_string.h"
#include "io.h"

static void	emit_token(t_msh_lexer *lexer,
				t_msh_lexer_token tok, char **input, char **iter)
{
	t_msh_lexer_data	*token;
	t_list				tmp;

	if (tok == LS_PARSING)
		return ;
	ft_memset(&tmp, 0, sizeof(t_list));
	token = malloc(sizeof(t_msh_lexer_data));
	if (!token)
		msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
	if ((*iter == *input && **input) || tok == LS_DQUOTE || tok == LS_SQUOTE)
		++(*iter);
	token->value = ft_strndup(*input, (*iter) - (*input));
	if (!token->value)
	{
		free(token);
		msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
	}
	token->at = *input;
	token->token = tok;
	tmp = (t_list){.lexer = lexer->datas};
	ft_lstaddback(&tmp, ft_lstnew(token));
	lexer->datas = tmp.lexer;
	*input = *iter;
}

static void	print_error_if_any(void)
{
	t_glob_lexer	*glexer;
	t_msh_glob		*glob;

	glexer = &(msh_glob_get()->lexer);
	glob = msh_glob_get();
	if (glexer->lexer.state == LS_PARSE_ERROR && !glexer->lexer.datas)
		msh_io_print_error(E_INVALID_PROMPT, glob->line);
	else if (glexer->lexer.state == LS_PARSE_ERROR)
		msh_io_print_error(E_INVALID_PROMPT,
			ft_lstlast(glexer->lexer.datas).lexer->content->at);
}

t_msh_lexer	*msh_lexer_parse(char *input)
{
	char						*iter;
	t_msh_lexer_token			tok;
	t_msh_lexer_state			old_state;
	t_msh_lexer					*lexer;
	int							(*table)[LS_FINISHED + 1];

	msh_lexer_exit();
	iter = input;
	lexer = &(msh_glob_get()->lexer.lexer);
	table = msh_glob_get()->lexer.fsm_lookup_table;
	while (lexer->state != LS_FINISHED && lexer->state != LS_PARSE_ERROR)
	{
		tok = msh_glob_get()->lexer.char_lookup_table[(unsigned char)*iter];
		old_state = lexer->state;
		lexer->state = table[lexer->state][tok];
		if (lexer->state == LS_PARSING || lexer->state == LS_FINISHED)
			emit_token(lexer, old_state, &input, &iter);
		else
			++iter;
	}
	print_error_if_any();
	msh_lexer_second_pass(lexer->datas);
	if (lexer->state == LS_PARSE_ERROR)
		msh_glob_get()->exec.exit_status = 2;
	return (lexer);
}
