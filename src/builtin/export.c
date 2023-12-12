/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:59:53 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/09 16:42:22 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	valid_env_name(char *var)
{
	int	i;

	i = 0;
	if (ft_isalpha(var[i]) == 0 && var[i] != '_')
		return (false);
	i++;
	while (var[i] && var[i] != '=')
	{
		if (ft_isalphanum(var[i]) == 0 && var[i] != '_')
		{
			if (var[i] == '+' && var[i + 1] == '=')
				return (true);
			return (false);
		}
		i++;
	}
	return (true);
}

static char	**get_env_name_and_value(char *arg)
{
	char	**tmp;
	char	*equal_pos;

	equal_pos = ft_strchr(arg, '=');
	tmp = malloc(sizeof * tmp * (2 + 1));
	tmp[0] = ft_substr(arg, 0, equal_pos - arg);
	tmp[1] = ft_substr(equal_pos, 1, ft_strlen(equal_pos));
	tmp[2] = NULL;
	return (tmp);
}

// int	compare_env_entries(const t_env *entry1, const t_env *entry2)
// {
// 	return (ft_strcmp(entry1->name, entry2->name));
// }

// void	bubble_sort_env_entries(t_env_buf *env)
// {
// 	size_t	n;
// 	int		swapped;
// 	size_t	i;
// 	t_env	temp;

// 	n = env->nbelem;
// 	swapped = 1;
// 	i = 1;
// 	while (swapped)
// 	{
// 		swapped = 0;
// 		i = 1;
// 		while (i < n)
// 		{
// 			if (compare_env_entries(&(env->buf[i - 1]), &(env->buf[i])) > 0)
// 			{
// 				temp = env->buf[i - 1];
// 				env->buf[i - 1] = env->buf[i];
// 				env->buf[i] = temp;
// 				swapped = 1;
// 			}
// 			i++;
// 		}
// 	}
// }

int	export_no_arg(char **args)
{
	size_t		i;
	t_env_buf	*tmp;

	tmp = &(msh_glob_get()->env);
	if (args && args[1])
		return (errormsg_cmd("env", NULL, "too many arguments", 2));
	bubble_sort_env_entries(tmp);
	i = 0;
	while (i < tmp->nbelem)
	{
		ft_putstrfd("export ", STDOUT_FILENO);
		ft_putstrfd(tmp->buf[i].name, STDOUT_FILENO);
		ft_putstrfd("=", STDOUT_FILENO);
		ft_putstrfd("\"", STDOUT_FILENO);
		ft_putstrfd((tmp->buf[i].value), STDOUT_FILENO);
		ft_putstrfd("\"", STDOUT_FILENO);
		ft_putstrfd("\n", STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}

// void	modif_tmp(char *var)
// {
// 	int	i;

// 	i = 0;
// 	while (var[i])
// 	{
// 		if (var[i] == '+' && var[i + 1] == '\0')
// 		{
// 			ft_strtrim(var, "+");
// 			break ;
// 		}
// 		i++;
// 	}
// }

int	export_builtin(char **args)
{
	int		i;
	int		ret;
	char	**tmp;

	ret = EXIT_SUCCESS;
	i = 1;
	if (!args[i])
		return (export_no_arg(NULL));
	while (args[i])
	{
		if (valid_env_name(args[i]) == false)
		{
			errormsg_cmd("export", args[i], "not a valid identifier", false);
			ret = EXIT_FAILURE;
		}
		else if (ft_strchr(args[i], '=') != NULL)
		{
			tmp = get_env_name_and_value(args[i]);
			modif_tmp(tmp[0]);
			msh_env_modif(tmp[0], tmp[1]);
			free_array(tmp);
		}
		i++;
	}
	return (ret);
}
