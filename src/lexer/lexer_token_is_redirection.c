/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_is_redirection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:21:27 by pierre            #+#    #+#             */
/*   Updated: 2023/09/25 15:21:27 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	lexer_token_is_redirection(int token)
{
	return (token >= LS_REDIRECT_RIGHT && token <= LS_REDIRECT_LEFT);
}
