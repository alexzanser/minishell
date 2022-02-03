/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:43:56 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/19 15:15:54 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*ft_find_command(t_arg *lst, char ***envp)
{
	(void)envp;
	while (lst)
	{
		if (!ft_is_pipe_or_redir(lst->content) && (!lst->prev
				|| (ft_strncmp(lst->prev->content, "<", 2)
					&& ft_strncmp(lst->prev->content, "<<", 3)))
			&& (!lst->prev || (ft_strncmp(lst->prev->content, ">", 2)
					&& ft_strncmp(lst->prev->content, ">>", 3))))
			break ;
		lst = lst->next;
	}
	return (lst);
}

int	ft_is_a_command(t_arg *lst)
{
	if (!lst)
		return (1);
	if (!lst->path && !ft_is_built_int(lst->content))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(lst->content, 2);
		ft_putstr_fd(" : command not found\n", 2);
		return (1);
	}
	return (0);
}
