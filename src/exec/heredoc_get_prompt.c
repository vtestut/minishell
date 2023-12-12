/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_get_prompt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:33:59 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/06 18:45:46 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/**
 * Generate the prompt for the given heredoc symbol
 *
 * @param end_symbol
 * @return
 */
char	*heredoc_get_prompt(const char *end_symbol)
{
	char	*str;
	char	*tmp;

	tmp = ft_strcat("heredoc (", end_symbol);
	str = ft_strcat(tmp, ") >>> ");
	free(tmp);
	return (str);
}
