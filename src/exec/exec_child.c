/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:41:58 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 18:31:24 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "builtin.h"
#include "init.h"
#include "utils.h"

static void	free_split_and_env(char **argv, char **envp)
{
	free_split(argv);
	free_split(envp);
}

static void	do_builtin(char **argv)
{
	is_builtin(argv[0])(argv);
	free_split(argv);
	close(msh_glob_get()->exec.pipes[0]);
	close(msh_glob_get()->exec.pipes[1]);
	msh_init_exit(0, NULL);
}

static void	replace_path(char **argv, char **envp)
{
	int		err;
	char	*p;

	p = NULL;
	err = exec_path_lookup(argv[0], &p);
	if (err)
	{
		msh_io_print_error(err, argv[0]);
		free_split_and_env(argv, envp);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		msh_init_exit(err, NULL);
	}
	free(argv[0]);
	argv[0] = p;
}

static void	do_redirect_and_heredoc(t_cmd_info cmd)
{
	int		err;

	err = exec_do_redirect(cmd);
	if (err)
		msh_init_exit(err, NULL);
	err = exec_do_heredoc(cmd);
	if (err)
		msh_init_exit(err, NULL);
}

void	exec_child(t_cmd_info cmd)
{
	char	**argv;
	char	**envp;

	if (msh_glob_get()->exec.state == ES_STOPPED)
		exit(EC_SUCCESS);
	do_redirect_and_heredoc(cmd);
	if (!ft_lstsize(cmd.command))
		exit(EC_SUCCESS);
	argv = lst2split(cmd.command);
	if (!argv)
		exit(EC_COMMAND_NOT_FOUND);
	else if (is_builtin(argv[0]))
		do_builtin(argv);
	envp = msh_env_get_envp();
	if (!envp)
		msh_init_exit_error(E_OUT_OF_MEMORY, (free_split(argv), NULL));
	replace_path(argv, envp);
	if (execve(argv[0], argv, envp))
	{
		free_split_and_env(argv, envp);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		msh_init_exit(errno, strerror(errno));
	}
}
