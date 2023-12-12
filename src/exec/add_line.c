/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:34:46 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/06 18:35:03 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*add_line(char *buff, char **line, const char *prompt)
{
	char	*tmp;

	tmp = ft_strcat(buff, *line);
	if (!tmp)
		return (NULL);
	free(buff);
	free(*line);
	buff = tmp;
	tmp = ft_strcat(buff, "\n");
	if (!tmp)
		return (free(buff), NULL);
	free(buff);
	*line = readline(prompt);
	return (tmp);
}
