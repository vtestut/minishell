/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:38:53 by pducloux          #+#    #+#             */
/*   Updated: 2023/12/06 16:17:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "types.h"
# include <stdlib.h>
# include <unistd.h>
# include "glob.h"

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

int		error_msg(char *str1, char *str2, char *str3, int erno);

/**
 * Initialization function for error module
 * 
 * @param argc
 * @param argv
 * @param env
*/
void	msh_error_init(int argc, char **argv, char **env);

int		errormsg_cmd(char *cmd, char *arg, char *strerror, int erno);

/**
 * Exit function for error module
*/
void	msh_error_exit(void);

void	free_ptr(void *ptr);

void	free_array(char **array);

#endif