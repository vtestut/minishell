/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_io_read_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:30:59 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/09 19:32:26 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "init.h"

int	check_history(char *line)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (line[i])
	{
		if (line[i] == c)
			i++;
		else
			return (0);
	}
	if (line[i] == '\0')
		return (1);
	return (0);
}

static char	*get_prompt(void)
{
	char	*prompt;

	prompt = ft_strcat("minishell", " $ ");
	if (!prompt)
		msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
	return (prompt);
}

static void	io_sigint(int sig)
{
	if (sig != SIGINT)
		return ;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	msh_glob_get()->exec.exit_status = 130;
}

char	*msh_io_read_input(void)
{
	char		*line;
	char		*prompt;
	t_msh_glob	*glob;

	signal(SIGINT, io_sigint);
	glob = msh_glob_get();
	line = NULL;
	prompt = get_prompt();
	line = readline(prompt);
	while (line && !ft_strlen(line))
	{
		free(line);
		line = readline(prompt);
	}
	free(prompt);
	if (!line)
		msh_init_exit(0, "exit\n");
	if (*line != '\0' && check_history(line) != 1)
		add_history(line);
	if (glob->line)
		free(glob->line);
	glob->line = line;
	return (line);
}
