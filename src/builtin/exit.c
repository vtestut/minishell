/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:48:22 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/09 21:20:39 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	free_arr(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

char	**ft_arrdup(char **arr)
{
	char	**ret;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	ret = ft_calloc(sizeof(char *), i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		ret[i] = ft_strdup(arr[i]);
		if (ret[i] == NULL)
		{
			free_arr(ret);
			return (ret);
		}
		i++;
	}
	return (ret);
}

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[0] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	get_exit_code(char **str)
{
	int	exit_code;

	exit_code = 0;
	if (!str[1])
		exit_code = msh_glob_get()->exec.exit_status;
	else if (is_str_digit(str[1]))
		exit_code = atoi(str[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	}
	free_arr(str);
	return (exit_code);
}

int	exit_builtin(char **args)
{
	char	**str;
	int		exit_code;

	exit_code = 0;
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (args[1] && args[2])
	{
		errormsg_cmd("exit", args[1], "too many arguments", EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	str = ft_arrdup(args);
	free_split(args);
	exit_code = get_exit_code(str);
	dup2(msh_glob_get()->exec.stdfds_backup[0], STDIN_FILENO);
	dup2(msh_glob_get()->exec.stdfds_backup[1], STDOUT_FILENO);
	dup2(msh_glob_get()->exec.stdfds_backup[2], STDERR_FILENO);
	close(msh_glob_get()->exec.stdfds_backup[0]);
	close(msh_glob_get()->exec.stdfds_backup[1]);
	close(msh_glob_get()->exec.stdfds_backup[2]);
	msh_init_exit(exit_code, NULL);
	return (EXIT_SUCCESS);
}

// void	free_arr(char **arr)
// {
// 	size_t	i;

// 	if (arr == NULL)
// 		return ;
// 	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		free(arr[i]);
// 		arr[i] = NULL;
// 		i++;
// 	}
// 	free(arr);
// }

// char	**ft_arrdup(char **arr)
// {
// 	char	**ret;
// 	size_t	i;

// 	i = 0;
// 	while (arr[i] != NULL)
// 		i++;
// 	ret = ft_calloc(sizeof(char *), i + 1);
// 	if (!ret)
// 		return (NULL);
// 	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		ret[i] = ft_strdup(arr[i]);
// 		if (ret[i] == NULL)
// 		{
// 			free_arr(ret);
// 			return (ret);
// 		}
// 		i++;
// 	}
// 	return (ret);
// }

// int	is_str_digit(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (!ft_isdigit(str[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	get_exit_code(char **str)
// {
// 	int	exit_code;

// 	exit_code = 0;
// 	if (!str[1])
// 		exit_code = msh_glob_get()->exec.exit_status;
// 	else if (is_str_digit(str[1]))
// 		exit_code = atoi(str[1]);
// 	else
// 	{
// 		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
// 		ft_putstr_fd(str[1], STDERR_FILENO);
// 		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
// 	}
// 	free_arr(str);
// 	return (exit_code);
// }

// int	exit_builtin(char **args)
// {
// 	char	**str;
// 	int		exit_code;

// 	exit_code = 0;
// 	ft_putendl_fd("exit", STDOUT_FILENO);
// 	if (args[1] && args[2])
// 	{
// 		errormsg_cmd("exit", args[1], "too many arguments", EXIT_FAILURE);
// 		return (EXIT_FAILURE);
// 	}
// 	str = ft_arrdup(args);
// 	free_split(args);
// 	exit_code = get_exit_code(str);
// 	dup2(msh_glob_get()->exec.stdfds_backup[0], STDIN_FILENO);
// 	dup2(msh_glob_get()->exec.stdfds_backup[1], STDOUT_FILENO);
// 	dup2(msh_glob_get()->exec.stdfds_backup[2], STDERR_FILENO);
// 	close(msh_glob_get()->exec.stdfds_backup[0]);
// 	close(msh_glob_get()->exec.stdfds_backup[1]);
// 	close(msh_glob_get()->exec.stdfds_backup[2]);
// 	msh_init_exit(exit_code, NULL);
// 	return (EXIT_SUCCESS);
// }
