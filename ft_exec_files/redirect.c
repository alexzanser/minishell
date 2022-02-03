/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:42:00 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/21 15:09:38 by kmercy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*ft_find_redirect(t_arg *lst)
{
	t_arg	*redirect;
	int		i;

	redirect = lst;
	i = 0;
	while (redirect && ft_strncmp(redirect->content, "<<", 3)
		&& ft_strncmp(redirect->content, "<", 2))
	{
		if (!ft_strncmp(redirect->content, "|", 2) && i != 0)
		{
			redirect = NULL;
			break ;
		}
		i++;
		redirect = redirect->next;
	}
	return (redirect);
}

void	ft_redirect(t_arg *redirect, char *file, char **envp)
{
	int	fd;

	(void)envp;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ;
	}
	else
		if (!ft_find_redirect(redirect->next))
			dup2(fd, 0);
}

char	**ft_redirect_in_command(t_arg *lst, char ***envp)
{
	t_arg	*needful;
	char	**args;

	args = NULL;
	needful = ft_find_redirect(lst);
	while (needful)
	{
		if (!ft_strncmp(needful->content, "<<", 3))
			ft_heredoc(needful, needful->next->content, *envp);
		else
		{
			ft_redirect(needful, needful->next->content, *envp);
		}
		args = ft_binding_args(args, needful->next->args, 0);
		needful = ft_find_redirect(needful->next);
	}
	return (args);
}

char	**ft_redirect_in_file(t_arg *lst, char ***envp)
{
	t_arg	*needful;
	char	**args;

	(void)envp;
	args = NULL;
	needful = ft_find_output(lst);
	while (needful)
	{
		if (ft_strlen(needful->content) == 1)
			ft_rewrite(needful->next->content);
		if (ft_strlen(needful->content) == 2)
			ft_add(needful->next->content);
		args = ft_binding_args(args, needful->next->args, 0);
		needful = ft_find_output(needful->next);
	}
	return (args);
}
