/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lexer_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:36:50 by pierre            #+#    #+#             */
/*   Updated: 2023/12/02 18:36:50 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_msh_lexer_data	*create_lexer_data(int token, char *value, const char *at)
{
	t_msh_lexer_data	*data;

	data = malloc(sizeof(t_msh_lexer_data));
	if (!data)
		return (NULL);
	data->token = token;
	data->value = value;
	data->at = (char *)at;
	return (data);
}
