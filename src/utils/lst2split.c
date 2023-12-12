/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:45:19 by pierre            #+#    #+#             */
/*   Updated: 2023/11/05 16:45:19 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**lst2split(t_list_lexer *cmdlst)
{
	char	**arr;
	size_t	arrlen;
	size_t	i;

	arrlen = ft_lstsize(cmdlst);
	arr = malloc(sizeof(char *) * (arrlen + 1));
	if (!arr)
		return (NULL);
	arr[arrlen] = NULL;
	i = 0;
	while (i < arrlen)
	{
		arr[i] = ft_strdup(cmdlst->content->value);
		cmdlst = cmdlst->next;
		i++;
	}
	return (arr);
}
