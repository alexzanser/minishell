/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:55:33 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/21 15:49:45 by kmercy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signal_handler_in_exec(int status, char **argv, char ***envp)
{
	WIFEXITED(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			ft_call_export(argv, envp, 130);
		if (WTERMSIG(status) == SIGQUIT)
			ft_call_export(argv, envp, 131);
	}
	else
	{
		if (status != 0)
			ft_call_export(argv, envp, 1);
		else
			ft_call_export(argv, envp, 0);
	}
}

void	ft_wait_all_child_processes(t_arg *lst, char ***envp)
{
	int		number_of_pipes;
	int		i;
	t_arg	*lst_saver;
	int		status;

	lst_saver = lst;
	number_of_pipes = 0;
	i = 0;
	status = 0;
	while (lst_saver)
	{
		if (!ft_strncmp(lst_saver->content, "|", 2))
			number_of_pipes++;
		lst_saver = lst_saver->next;
	}
	while (i < number_of_pipes)
	{
		waitpid(0, &status, 0);
		i++;
	}
	signal_handler_in_exec(status, lst->args, envp);
}

void	ft_add_command_after_pipe(int	*in_out, t_arg	*needful, char ***envp)
{
	t_arg	*arg_l;
	char	*args_str;
	int		in_out_2[2];

	in_out_2[0] = dup(0);
	in_out_2[1] = dup(1);
	dup2(in_out[0], 0);
	dup2(in_out[1], 1);
	args_str = readline("> ");
	if (!args_str)
	{
		ft_putstr_fd("bash: syntax error: unexpected end of file\n", 2);
		exit(1);
	}
	arg_l = NULL;
	ft_parse_input_str(args_str, &arg_l);
	ft_handle_envps(arg_l, *envp);
	ft_set_funcs_structure(arg_l, &needful);
	ft_set_path(needful, ft_return_env(*envp, "PATH"), envp);
	ft_free_argl_func_l_argstr(&arg_l, NULL, args_str);
	dup2(in_out_2[0], 0);
	dup2(in_out_2[1], 1);
}

void	ft_every_pipe(t_arg	*needful, int	*in_out, char ***envp)
{
	t_arg	*command;
	char	**args;

	if (!ft_strncmp(needful->content, "|", 2) && !needful->next)
		ft_add_command_after_pipe(in_out, needful, envp);
	args = ft_redirect_in_command(needful, envp);
	args = ft_binding_args(args, ft_redirect_in_file(needful, envp), 1);
	command = ft_find_command(needful, envp);
	if (!ft_is_a_command(command))
	{
		args = ft_binding_args(command->args, args, 1);
		if (!ft_find_output_int(needful)
			|| ft_find_pipe_int(needful->next))
		{
			ft_return(command->path, args, envp);
			dup2(in_out[1], 1);
			if (ft_find_redirect(ft_find_pipe(needful->next)))
				dup2(in_out[0], 0);
		}
		else if (!ft_find_pipe_int(needful->next)
			&& ft_find_output_int(needful))
			ft_pipe(command->path, args, envp);
		if (ft_array_cpm(args, command->args))
			ft_free(args);
	}
}

void	ft_exec(t_arg *lst, char ***envp)
{
	int		in_out[2];
	t_arg	*pipe;
	int		error;

	in_out[0] = dup(0);
	in_out[1] = dup(1);
	error = dup(2);
	if (lst)
	{
		if (lst->next == NULL)
			ft_return_one_command(lst->path, lst->args, envp);
		else
		{
			pipe = lst;
			while (pipe)
			{
				ft_every_pipe(pipe, in_out, envp);
				pipe = ft_find_pipe(pipe->next);
			}
			ft_wait_all_child_processes(lst, envp);
		}
	}
	dup2(in_out[0], 0);
	dup2(in_out[1], 1);
	dup2(error, 2);
}
