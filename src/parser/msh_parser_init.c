/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:21:27 by pierre            #+#    #+#             */
/*   Updated: 2023/09/25 15:21:27 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "glob.h"

void	msh_parser_init(int argc, char **argv, char **env)
{
	t_glob_parser	*parser;

	(void)argc;
	(void)argv;
	(void)env;
	parser = &(msh_glob_get()->parser);
	ft_memset(parser, 0, sizeof(t_glob_parser));
	parser->state = PS_OK;
}
