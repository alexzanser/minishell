/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:11:21 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/19 13:11:21 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*ft_find_output(t_arg *lst)
{
	t_arg	*output;
	int		i;

	output = lst;
	i = 0;
	while (output && ft_strncmp(output->content, ">>", 3)
		&& ft_strncmp(output->content, ">", 2))
	{
		if (!ft_strncmp(output->content, "|", 2) && i != 0)
		{
			output = NULL;
			break ;
		}
		i++;
		output = output->next;
	}
	return (output);
}

int	ft_find_output_int(t_arg *lst)
{
	t_arg	*output;
	int		i;

	output = lst;
	i = 0;
	while (output && ft_strncmp(output->content, ">>", 3)
		&& ft_strncmp(output->content, ">", 2))
	{
		if (!ft_strncmp(output->content, "|", 2) && i != 0)
		{
			output = NULL;
			break ;
		}
		i++;
		output = output->next;
	}
	if (output)
		return (0);
	else
		return (1);
}

t_arg	*ft_find_pipe(t_arg *lst)
{
	t_arg	*pipe;

	pipe = lst;
	while (pipe && ft_strncmp(pipe->content, "|", 2))
	{
		pipe = pipe->next;
	}
	return (pipe);
}

int	ft_find_pipe_int(t_arg *lst)
{
	t_arg	*pipe;

	pipe = lst;
	while (pipe && ft_strncmp(pipe->content, "|", 2))
	{
		pipe = pipe->next;
	}
	if (pipe)
		return (0);
	else
		return (1);
}
