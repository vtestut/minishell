/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_do_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:03:29 by pierre            #+#    #+#             */
/*   Updated: 2023/11/27 01:03:29 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	write_heredoc(t_cmd_info cmd)
{
	int	fd;

	fd = open("/tmp/msh-heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (errno);
	if (cmd.heredoc_str)
		write(fd, cmd.heredoc_str, ft_strlen(cmd.heredoc_str));
	close(fd);
	return (0);
}

int	exec_do_heredoc(t_cmd_info cmd)
{
	int	fd;

	if (!cmd.heredoc)
		return (0);
	if (write_heredoc(cmd))
		return (1);
	fd = open("/tmp/msh-heredoc", O_RDONLY | O_CREAT, 0644);
	if (fd < 0)
		return (errno);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		close(fd);
		printf("%s\n", strerror(errno));
		return (errno);
	}
	close(fd);
	return (0);
}
