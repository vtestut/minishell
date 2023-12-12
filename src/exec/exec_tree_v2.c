/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:40:51 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 19:36:00 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	dup_and_do(t_cmd_info *cmd)
{
	if (cmd->fdin != STDIN_FILENO)
	{
		if (dup2(cmd->fdin, STDIN_FILENO) < 0)
			msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
		else
			close(cmd->fdin);
	}
	if (cmd->fdout != STDOUT_FILENO)
	{
		if (dup2(cmd->fdout, STDOUT_FILENO) < 0)
			msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
		else
			close(cmd->fdout);
	}
	close_all_pipes();
	exec_child(*cmd);
}

static int	exec_pipe_cmd(t_cmd_info *cmd)
{
	if (!cmd->command)
		return (0);
	cmd->pid = fork();
	if (cmd->pid < 0)
		return (0);
	else if (cmd->pid)
	{
		if (cmd->fdin != STDIN_FILENO)
			close(cmd->fdin);
		if (cmd->fdout != STDOUT_FILENO)
			close(cmd->fdout);
		return (1);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		return (dup_and_do(cmd), 1);
	}
}

static void	wait_childs(t_ft_btree_node *tree)
{
	int				wstatus;
	t_glob_exec		*gexec;
	int				err;

	gexec = &(msh_glob_get()->exec);
	while (tree->type == PP_PIPE)
	{
		err = waitpid(0, &wstatus, 0);
		if (err != -1 && WIFSIGNALED(wstatus))
			gexec->exit_status = WTERMSIG(wstatus) + 128;
		else if (err != -1 && WIFEXITED(wstatus))
			gexec->exit_status = WEXITSTATUS(wstatus);
		tree = tree->second;
	}
	err = waitpid(0, &wstatus, 0);
	if (err != -1 && WIFSIGNALED(wstatus))
		gexec->exit_status = WTERMSIG(wstatus) + 128;
	else if (err != -1 && WIFEXITED(wstatus))
		gexec->exit_status = WEXITSTATUS(wstatus);
}

static void	exec_single(t_ft_btree_node *tree)
{
	t_cmd_info	*cmd;
	int			wstatus;
	char		**argv;

	cmd = &(tree->content->command);
	argv = lst2split(cmd->command);
	if (!argv)
		msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
	else if (!*argv)
		return (free_split(argv), (void)0);
	if (is_builtin(argv[0]))
	{
		free_split(argv);
		exec_builtin_non_fork(tree->content->command);
	}
	else
	{
		free_split(argv);
		exec_pipe_cmd(cmd);
		waitpid(cmd->pid, &wstatus, 0);
		if (WIFSIGNALED(wstatus))
			msh_glob_get()->exec.exit_status = WTERMSIG(wstatus) + 128;
		if (WIFEXITED(wstatus))
			msh_glob_get()->exec.exit_status = WEXITSTATUS(wstatus);
	}
}

void	exec_tree_v2(t_ft_btree_node *tree)
{
	t_ft_btree_node	*tmp;

	if (!tree || msh_glob_get()->sig == SIGINT
		|| msh_glob_get()->exec.state == ES_STOPPED)
		return ;
	tmp = tree;
	if (tree->type != PP_PIPE)
		exec_single(tree);
	else
	{
		exec_pipe_cmd(&(tree->first->content->command));
		while (tree->second->type == PP_PIPE)
		{
			tree = tree->second;
			exec_pipe_cmd(&(tree->first->content->command));
		}
		exec_pipe_cmd(&(tree->second->content->command));
		wait_childs(tmp);
	}
}
