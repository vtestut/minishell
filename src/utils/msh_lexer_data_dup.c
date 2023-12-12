/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer_data_dup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:29:01 by pierre            #+#    #+#             */
/*   Updated: 2023/10/30 17:29:01 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_msh_lexer_data	*msh_lexer_data_dup(t_msh_lexer_data *data)
{
	t_msh_lexer_data	*new;

	new = ft_memdup(data, sizeof(t_msh_lexer_data));
	if (!new)
		return (NULL);
	new->value = ft_strdup(data->value);
	if (!new->value)
		return (free(new), NULL);
	return (new);
}
