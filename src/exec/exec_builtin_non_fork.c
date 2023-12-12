/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_non_fork.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:41:58 by pierre            #+#    #+#             */
/*   Updated: 2023/12/06 16:22:26 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	dup_std_fds(int fdbackups[3])
{
	fdbackups[0] = dup(STDIN_FILENO);
	if (fdbackups[0] < 0)
		return (0);
	fdbackups[1] = dup(STDOUT_FILENO);
	if (fdbackups[1] < 0)
	{
		close(fdbackups[0]);
		return (0);
	}
	fdbackups[2] = dup(STDERR_FILENO);
	if (fdbackups[2] < 0)
	{
		close(fdbackups[0]);
		close(fdbackups[1]);
		return (0);
	}
	ft_memcpy(msh_glob_get()->exec.stdfds_backup, fdbackups, sizeof(int) * 3);
	return (1);
}

static void	close_backup_fds(int fds[3])
{
	close(fds[0]);
	close(fds[1]);
	close(fds[2]);
}

static int	restore_std_fds(int fds[3])
{
	if (dup2(fds[0], STDIN_FILENO) < 0)
		return (close_backup_fds(fds), 0);
	if (dup2(fds[1], STDOUT_FILENO) < 0)
		return (close_backup_fds(fds), 0);
	if (dup2(fds[2], STDERR_FILENO) < 0)
		return (close_backup_fds(fds), 0);
	close_backup_fds(fds);
	return (1);
}

void	exec_builtin_non_fork(t_cmd_info cmd)
{
	int			fdbackups[3];
	t_glob_exec	*gexec;
	char		**args;

	gexec = &(msh_glob_get()->exec);
	if (!dup_std_fds(fdbackups))
		return ;
	if (exec_do_redirect(cmd))
		gexec->exit_status = 1;
	else if (exec_do_heredoc(cmd))
		gexec->exit_status = 1;
	else
	{
		args = lst2split(cmd.command);
		if (!args)
			msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
		gexec->exit_status = is_builtin(cmd.command->content->value)(args);
		free_split(args);
	}
	if (!restore_std_fds(fdbackups))
		return ;
}
