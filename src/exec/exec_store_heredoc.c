/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_store_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:54:01 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 20:48:32 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/**
 * This function is used to gain one line of code (norminette)
 * @param line
 * @param prompt
 */
static void	free_both(void *line, void *prompt)
{
	free(line);
	free(prompt);
}

static void	h_sigint(int sig)
{
	(void)sig;
	msh_glob_get()->exec.state = ES_STOPPED;
	msh_glob_get()->sig = SIGINT;
	msh_glob_get()->exec.exit_status = 130;
}

static int	custom_event_hook(void)
{
	if (msh_glob_get()->exec.state == ES_STOPPED)
	{
		rl_done = 1;
		rl_callback_sigcleanup();
		return (1);
	}
	return (0);
}

static void	setup(char **buff, t_list_heredoc **heredoc,
		t_cmd_info *cmd_info)
{
	*buff = NULL;
	msh_glob_get()->exec.state = ES_HEREDOC;
	signal(SIGINT, h_sigint);
	rl_event_hook = custom_event_hook;
	*heredoc = ft_lstlast(cmd_info->heredoc).heredoc;
	msh_glob_get()->exec.current_heredoc = *heredoc;
}

void	exec_store_heredoc(t_cmd_info *cmd_info)
{
	t_list_heredoc	*heredoc;
	char			*buff;
	char			*line;
	char			*prompt;

	setup(&buff, &heredoc, cmd_info);
	if (msh_glob_get()->exec.state == ES_STOPPED)
		return ;
	if (!heredoc)
	{
		msh_glob_get()->exec.state = ES_RUNNING;
		return ;
	}
	prompt = heredoc_get_prompt(heredoc->content);
	line = readline(prompt);
	while (line && ft_strcmp(line, heredoc->content)
		&& msh_glob_get()->exec.state == ES_HEREDOC)
		buff = add_line(buff, &line, prompt);
	free_both(line, prompt);
	cmd_info->heredoc_str = h_substitute(buff);
	if (msh_glob_get()->exec.state == ES_HEREDOC)
		msh_glob_get()->exec.state = ES_RUNNING;
}
