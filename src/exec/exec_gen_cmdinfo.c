/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_gen_cmdinfo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:07:41 by pierre            #+#    #+#             */
/*   Updated: 2023/12/06 18:51:18 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "lexer.h"

static int	process_redirect(t_list_redirect *redir,
				t_msh_lexer_data d, int offset)
{
	redir->content->type = d.token;
	redir->content->file = ft_strdup(d.value + offset);
	if (!redir->content->file)
		return (0);
	return (1);
}

static t_list_redirect	*redirect_transform(t_list_redirect *redir)
{
	t_msh_lexer_data	tmp;
	t_list_redirect		*tmplst;
	int					offset;

	tmplst = redir;
	while (redir)
	{
		tmp = *(((t_list_lexer *)redir)->content);
		if (tmp.token == LS_AREDIRECT_RIGHT)
			offset = 2;
		else
			offset = 1;
		if (!process_redirect(redir, tmp, offset))
			return (NULL);
		free(tmp.value);
		redir = redir->next;
	}
	return (tmplst);
}

static t_list_heredoc	*heredoc_transform(t_list_heredoc *lst)
{
	char			*stop;
	t_list_heredoc	*tmp;
	t_list_lexer	*cast;

	cast = (t_list_lexer *)lst;
	tmp = lst;
	while (lst)
	{
		stop = ft_strdup(cast->content->value + 2);
		free(cast->content->value);
		free(cast->content);
		lst->content = stop;
		lst = lst->next;
		cast = (t_list_lexer *)lst;
	}
	return (tmp);
}

static void	finish(t_list placeholder[3], t_cmd_info *cmd_info)
{
	cmd_info->command = placeholder[0].lexer;
	cmd_info->redir = redirect_transform(placeholder[1].redirect);
	cmd_info->heredoc = heredoc_transform(placeholder[2].heredoc);
	cmd_info->fdin = STDIN_FILENO;
	cmd_info->fdout = STDOUT_FILENO;
	exec_store_heredoc(cmd_info);
}

t_cmd_info	exec_gen_cmdinfo(t_list_lexer *cmd)
{
	t_cmd_info		cmd_info;
	t_list_lexer	*toks;
	t_list_lexer	*tmp;
	t_list			placeholder[3];

	ft_memset(&cmd_info, 0, sizeof(t_cmd_info));
	ft_memset(placeholder, 0, sizeof(t_list) * 3);
	toks = cmd;
	while (toks)
	{
		tmp = toks;
		toks = toks->next;
		tmp->next = NULL;
		if (lexer_token_is_command(tmp->content->token))
			ft_lstaddback(&(placeholder[0]), tmp);
		else if (lexer_token_is_redirection(tmp->content->token))
			ft_lstaddback(&(placeholder[1]), tmp);
		else
			ft_lstaddback(&(placeholder[2]), tmp);
	}
	finish(placeholder, &cmd_info);
	return (cmd_info);
}
