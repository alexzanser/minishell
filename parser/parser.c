/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:07:08 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/21 13:03:51 by kmercy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_set_func_args(t_arg **arg_l, t_arg **func_l)
{
	char	**arr;

	arr = ft_calloc(2, sizeof (char *));
	if ((!ft_is_pipe_or_redir((*arg_l)->content)) || (!ft_is_pipe_or_redir(
				(*arg_l)->content) && (*arg_l)->prev->prev && !ft_strncmp(
				(*arg_l)->prev->prev->content, "<<", 3)))
	{
		if ((*arg_l)->content)
		{
			ft_args_control(arg_l, &arr);
		}
		while ((*arg_l) && !ft_is_pipe_or_redir((*arg_l)->content))
		{
			ft_args_control(arg_l, &arr);
		}
	}
	else
		(*arg_l) = (*arg_l)->next;
	ft_lst2add_args(func_l, arr);
}

void	ft_remove_quotes_func(t_arg *func_l)
{
	int		i;

	while (func_l)
	{
		i = 0;
		if (func_l->args && ft_strncmp(func_l->content, "export", 7))
		{
			while (func_l->args[i])
			{
				if (*(func_l->args[i]) == '\"' && ft_closed_quote(
						ft_strchr(func_l->args[i], '\"')))
					ft_remove_quotes(ft_strchr(func_l->args[i], '\"'));
				else if (*(func_l->args[i]) == '\'' && ft_closed_quote(
						ft_strchr(func_l->args[i], '\'')))
					ft_remove_quotes(ft_strchr(func_l->args[i], '\''));
				i++;
			}
		}
		func_l = func_l->next;
	}
}

void	ft_set_funcs_structure(t_arg *arg_l, t_arg **func)
{
	static int		command_exists;

	command_exists = 0;
	while (arg_l)
	{
		if (arg_l->next && ft_is_pipe_or_redir(arg_l->content)
			&& ft_strncmp(arg_l->content, "|", 3))
		{
			ft_lst2add_back(func, ft_lst2_new(ft_strdup(arg_l->content)));
			ft_lst2add_back(func, ft_lst2_new(ft_strdup(arg_l->next->content)));
			if (command_exists == 0)
			{
				arg_l = arg_l->next->next;
				continue ;
			}
			else
				arg_l = arg_l->next;
		}
		else if (arg_l->content)
		{
			ft_lst2add_back(func, ft_lst2_new(ft_strdup(arg_l->content)));
			command_exists = 1;
		}
		ft_set_func_args(&arg_l, func);
	}
}

void	ft_parse_input_str(char *arg_str, t_arg **arg_l)
{
	char	*arg;

	while (*arg_str)
	{
		while (ft_is_space(*arg_str))
			arg_str++;
		if ((*arg_str == '\'' || *arg_str == '\"') && ft_closed_quote(arg_str))
			arg_str += ft_pull(arg_str, &arg, ft_closed_quote(arg_str));
		else if (*arg_str == '>' || *arg_str == '<')
		{
			if (*(arg_str + 1) == *arg_str)
				arg_str += ft_pull(arg_str, &arg, 2);
			else
				arg_str += ft_pull(arg_str, &arg, 1);
		}
		else if ((*arg_str == '\'' || *arg_str == '\"'))
			arg_str += ft_pull(arg_str, &arg, ft_next_space_pipe(arg_str));
		else if (*arg_str == '|')
			arg_str += ft_pull(arg_str, &arg, 1);
		else
			arg_str += ft_pull(arg_str, &arg, ft_next_other(arg_str));
		while (ft_is_space(*arg_str))
			arg_str++;
		ft_lst2add_back(arg_l, ft_lst2_new(arg));
	}
}

int	main(int argc, char **argv, char **envp)
{
	static char			*args_str;
	char				**env_array;
	t_arg				*arg_l;
	t_arg				*func_l;
	int					history_fd;

	history_fd = open(".history", O_RDWR | O_APPEND | O_CREAT, 0777);
	ft_read_history(history_fd);
	env_array = ft_char_array_cpy(envp);
	while (1)
	{
		ft_sig_parent();
		args_str = readline("minishell$ ");
		ft_check_eof(args_str, env_array);
		ft_write_history(history_fd, args_str, argc, argv);
		ft_parse_input_str(args_str, &arg_l);
		ft_handle_envps(arg_l, env_array);
		ft_set_funcs_structure(arg_l, &func_l);
		ft_remove_quotes_func(func_l);
		if (!ft_check_syntax_errors(func_l))
			if (func_l && !ft_set_path(func_l,
					ft_return_env(env_array, "PATH"), &env_array))
				ft_exec(func_l, &env_array);
		ft_free_argl_func_l_argstr(&arg_l, &func_l, args_str);
	}
}
