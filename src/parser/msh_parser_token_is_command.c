/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser_token_is_command.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:21:27 by pierre            #+#    #+#             */
/*   Updated: 2023/09/25 15:21:27 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"

int	msh_parser_token_is_command(int token)
{
	return (token >= LS_WORD && token <= LS_HEREDOC);
}
