/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_funcs_3_checkers_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:02:24 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_check_eof(char *args_str, char **env_array)
{
	if (!args_str)
	{
		ft_putstr_fd("exit\n", 2);
		exit(ft_atoi(ft_return_env(env_array, "?")));
	}
}

int	ft_is_built_int(char *func_name)
{
	if (!ft_strncmp(func_name, "pwd", 4))
		return (1);
	if (!ft_strncmp(func_name, "cd", 3))
		return (1);
	if (!ft_strncmp(func_name, "echo", 5))
		return (1);
	if (!ft_strncmp(func_name, "unset", 6))
		return (1);
	if (!ft_strncmp(func_name, "export", 7))
		return (1);
	if (!ft_strncmp(func_name, "env", 4))
		return (1);
	if (!ft_strncmp(func_name, "exit", 5))
		return (1);
	return (0);
}

int	ft_check_syntax_errors(t_arg *func_l)
{
	while (func_l)
	{
		if (ft_is_pipe_or_redir(func_l->content)
			&& ((!func_l->prev && !func_l->next) || (!func_l->prev
					&& !ft_strncmp(func_l->content, "|", 2)) || (!func_l->next
					&& ft_strncmp(func_l->content, "|", 2)) || (func_l->next
					&& ft_is_pipe_or_redir(func_l->next->content))))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("syntax error near unexpected token '", 2);
			if (func_l->next && ft_is_pipe_or_redir(func_l->next->content))
				ft_putstr_fd(func_l->next->content, 2);
			else
				ft_putstr_fd(func_l->content, 2);
			ft_putstr_fd("'\n", 2);
			return (1);
		}
		func_l = func_l->next;
	}
	return (0);
}
