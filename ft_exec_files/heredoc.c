/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:28:48 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/19 17:57:59 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*ft_find_heredoc(t_arg *lst)
{
	t_arg	*heredoc;

	heredoc = lst;
	while (heredoc && ft_strncmp(heredoc->content, "<<", 3))
	{
		heredoc = heredoc->next;
	}
	return (heredoc);
}

void	ft_child_logic(int *pip, char *stop, char **envp)
{
	char	*args_str;

	ft_sig_child_heredoc();
	args_str = readline("> ");
	while (ft_strncmp(args_str, stop, ft_strlen(stop) + 1))
	{
		while (ft_strchr(args_str, '\"')
			&& ft_closed_quote(ft_strchr(args_str, '\"'))
			&& ft_strchr(args_str, '$'))
			ft_replace_by_envp(&args_str, envp);
		while (!(ft_strchr(args_str, '\'')
				&& ft_closed_quote(ft_strchr(args_str, '\'')))
			&& ft_strchr(args_str, '$'))
			ft_replace_by_envp(&args_str, envp);
		write(pip[1], args_str, ft_strlen(args_str));
		write(pip[1], "\n", 1);
		args_str = readline("> ");
	}
	close(pip[1]);
	close(pip[0]);
	exit (0);
}

void	ft_heredoc(t_arg *heredoc, char *stop, char **envp)
{
	int		pip[2];
	int		pid;

	pipe(pip);
	pid = fork();
	if (!pid)
	{
		ft_child_logic(pip, stop, envp);
	}
	else
	{
		ft_sig_ignore();
		if (!ft_find_redirect(heredoc->next))
		{
			close(pip[1]);
			dup2(pip[0], 0);
			close(pip[0]);
		}
		waitpid(0, NULL, 0);
	}
}
