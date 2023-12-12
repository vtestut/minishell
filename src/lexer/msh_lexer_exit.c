/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:00:39 by pducloux          #+#    #+#             */
/*   Updated: 2023/06/17 19:09:41 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	msh_lexer_exit(void)
{
	t_msh_lexer	*lexer;

	lexer = &(msh_glob_get()->lexer.lexer);
	if (lexer->datas)
		ft_lstclear((t_list_lexer *)lexer->datas,
			(void (*)(void *))msh_lexer_free_data);
	ft_memset(&(msh_glob_get()->lexer.lexer), 0, sizeof(t_msh_lexer));
}
