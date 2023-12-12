/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:54:33 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 18:27:24 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "glob.h"
#include "builtin.h"
#include "utils.h"
#include <stdlib.h>

static int	create_pipes(t_ft_btree_node *tree)
{
	int	pipefd[2];

	while (tree->type == PP_PIPE)
	{
		if (pipe(pipefd) < 0)
			return (0);
		tree->first->content->command.fdout = pipefd[1];
		if (tree->second->type == PP_PIPE)
			tree->second->first->content->command.fdin = pipefd[0];
		else
			tree->second->content->command.fdin = pipefd[0];
		tree = tree->second;
	}
	return (1);
}

void	msh_exec(void)
{
	t_ft_btree_node	*tree;
	t_ft_btree_node	*ptree;
	t_glob_exec		*gexec;

	exec_exit();
	gexec = &(msh_glob_get()->exec);
	gexec->state = ES_RUNNING;
	if (msh_glob_get()->parser.state == PS_ERROR)
		return ;
	ptree = msh_glob_get()->parser.tree;
	if (!ptree)
		return ;
	tree = exec_gen_tree(ptree);
	msh_glob_get()->exec.tree = tree;
	if (tree && !create_pipes(tree))
		msh_init_exit_error(E_OUT_OF_MEMORY, NULL);
	if (tree && gexec->state == ES_RUNNING)
		exec_tree_v2(tree);
	gexec->state = ES_DONE;
	gexec->pid = -1;
}
