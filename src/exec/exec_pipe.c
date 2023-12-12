/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 01:31:17 by pierre            #+#    #+#             */
/*   Updated: 2023/11/28 01:31:17 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "init.h"

typedef union u_pipe {
	int	b[2];
	struct s_p {
		int	r;
		int	w;
	}	p;
}	t_pipe;

static void	do_pipe_child(t_ft_btree_node *nd, t_pipe pipe, int read_that)
{
	t_cmd_info	cmd;
	int			fd;

	cmd = nd->content->command;
	if (!(cmd.cmd_flags & E_CMD_FIRST))
	{
		fd = dup2(read_that, STDIN_FILENO);
		if (fd < 0)
			exit(errno);
	}
	if (!(cmd.cmd_flags & E_CMD_LAST))
	{
		fd = dup2(pipe.p.w, STDOUT_FILENO);
		if (fd < 0)
			exit(errno);
	}
	exec_child(cmd);
}

static void	wait_child(pid_t pid, t_pipe pipefd)
{
	int				wstatus;
	t_glob_exec		*gexec;

	gexec = &(msh_glob_get()->exec);
	msh_glob_get()->exec.pid = pid;
	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		gexec->exit_status = WEXITSTATUS(wstatus);
		msh_env_modif("?", ft_itoa(gexec->exit_status));
	}
	if (gexec->read_that > 0)
		close(gexec->read_that);
	close(pipefd.p.w);
	gexec->read_that = pipefd.p.r;
}

void	exec_pipe(t_ft_btree_node **nd)
{
	pid_t				pid;
	struct s_glob_exec	*gexec;
	t_pipe				pipefd;

	gexec = &(msh_glob_get()->exec);
	if (pipe(pipefd.b))
		msh_init_exit_error(EC_FAILURE, NULL);
	ft_memcpy(gexec->pipes, pipefd.b, sizeof(int) * 2);
	pid = fork();
	if (pid < 0)
	{
		printf("[ERROR]: %s\n", strerror(errno));
		return ;
	}
	else if (!pid)
	{
		if ((*nd)->type == PP_PIPE)
			do_pipe_child((*nd)->first, pipefd, gexec->read_that);
		else
			do_pipe_child((*nd), pipefd, gexec->read_that);
	}
	else
		wait_child(pid, pipefd);
}
