/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_do_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:39:42 by pierre            #+#    #+#             */
/*   Updated: 2023/12/09 18:46:24 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	check_directory(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY | O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		write(2, "minishell: ", 11);
		write(2, file, ft_strlen(file));
		write(2, ": is a directory\n", 17);
		return (1);
	}
	return (0);
}

static int	do_redirect_left(t_list_redirect *r)
{
	int	fd;

	if (check_directory(r->content->file))
		return (1);
	fd = open(r->content->file, O_RDONLY);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
		return (errno);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		close(fd);
		printf("%s\n", strerror(errno));
		return (errno);
	}
	close(fd);
	return (0);
}

static int	do_redirect_right(t_list_redirect *r)
{
	int	fd;

	if (check_directory(r->content->file))
		return (1);
	fd = open(r->content->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
		return (errno);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		close(fd);
		printf("%s\n", strerror(errno));
		return (errno);
	}
	close(fd);
	return (0);
}

static int	do_aredirect_right(t_list_redirect *r)
{
	int	fd;

	if (check_directory(r->content->file))
		return (1);
	fd = open(r->content->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
		return (errno);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		close(fd);
		printf("%s\n", strerror(errno));
		return (errno);
	}
	close(fd);
	return (0);
}

int	exec_do_redirect(t_cmd_info cmd)
{
	t_list_redirect	*tmp;
	int				err;

	if (!cmd.redir)
		return (0);
	tmp = cmd.redir;
	while (tmp)
	{
		if (tmp->content->type == LS_REDIRECT_LEFT)
			err = do_redirect_left(tmp);
		else if (tmp->content->type == LS_REDIRECT_RIGHT)
			err = do_redirect_right(tmp);
		else if (tmp->content->type == LS_AREDIRECT_RIGHT)
			err = do_aredirect_right(tmp);
		else
			err = 0;
		tmp = tmp->next;
		if (err)
			return (1);
	}
	return (0);
}
