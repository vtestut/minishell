/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:27:55 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/09 19:35:39 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "ft_string.h"
#include "init.h"
#include <stdio.h>
#include <termios.h>

static void	exec_line(char *line, t_msh_glob *glob)
{
	msh_lexer_parse(line);
	if (glob->lexer.lexer.state == LS_FINISHED)
	{
		msh_parser_parse();
		if (glob->parser.state == PS_OK)
			msh_exec();
	}
}

int	main(int argc, char **argv, char **env)
{
	t_msh_glob	*glob;

	rl_catch_signals = 1;
	msh_init_init(argc, argv, env);
	signal(SIGQUIT, SIG_IGN);
	glob = msh_glob_get();
	(void)msh_io_read_input();
	ft_strtrim(glob->line, " \t\n\r\v\f");
	while (glob->line != NULL)
	{
		if (ft_strlen(glob->line))
			exec_line(glob->line, glob);
		free(glob->line);
		glob->line = NULL;
		(void)msh_io_read_input();
		ft_strtrim(glob->line, " \t\n\r\v\f");
	}
	return (0);
}
