/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:56:36 by pducloux          #+#    #+#             */
/*   Updated: 2023/11/27 20:42:48 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	init_lookup_table(int *table)
{
	int	tmp;

	tmp = LS_WORD;
	ft_memelemset(table, &tmp, sizeof(int), sizeof(int) * 256);
	tmp = LS_NUMBER;
	ft_memelemset(table + '0', &tmp, sizeof(int), ('9' - '0') * sizeof(int));
	table[' '] = LS_SEPARATOR;
	table['\t'] = LS_SEPARATOR;
	table['\''] = LS_SQUOTE;
	table['"'] = LS_DQUOTE;
	table['|'] = LS_PIPE;
	table['<'] = LS_REDIRECT_LEFT;
	table['>'] = LS_REDIRECT_RIGHT;
	table['\0'] = LS_FINISHED;
}

void	msh_lexer_init(int argc, char **argv, char **envp)
{
	t_msh_glob	*glob;

	(void)argc;
	(void)argv;
	(void)envp;
	glob = msh_glob_get();
	init_lookup_table(glob->lexer.char_lookup_table);
	msh_lexer_init_fsm(glob->lexer.fsm_lookup_table);
}
