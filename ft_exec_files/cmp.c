/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:20:42 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/19 17:46:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_count_output(t_arg *output)
{
	int	n_output;

	n_output = -1;
	if (output && (!ft_strncmp(output->content, ">>", 3)
			|| !ft_strncmp(output->content, ">", 2)))
		n_output++;
	while (output && ft_strncmp(output->content, ">>", 3)
		&& ft_strncmp(output->content, ">", 2))
	{
		output = output->next;
		n_output++;
	}
	return (n_output);
}

static int	ft_count_pipe(t_arg	*pipe)
{
	int		n_pipe;

	n_pipe = -1;
	if (pipe && !ft_strncmp(pipe->content, "|", 2))
		n_pipe++;
	while (pipe && ft_strncmp(pipe->content, "|", 2))
	{
		pipe = pipe->next;
		n_pipe++;
	}
	return (n_pipe);
}

int	ft_lstcmp(t_arg *lst)
{
	int		n_pipe;
	int		n_output;

	n_pipe = ft_count_pipe(lst);
	n_output = ft_count_output(lst);
	if (n_pipe == n_output)
		return (-1);
	if (n_pipe >= 0 && n_output >= 0)
	{
		if (n_pipe > n_output)
			return (0);
		else
			return (1);
	}
	else
	{
		if (n_pipe < 0)
			return (0);
		else
			return (1);
	}
}

int	ft_array_cpm(char **args_first, char **args_second)
{
	int	count_first;
	int	count_second;
	int	i;

	count_first = 0;
	count_second = 0;
	if (args_first)
		while (args_first[count_first])
			count_first++;
	if (args_second)
		while (args_second[count_second])
			count_second++;
	if (count_first != count_second)
		return (1);
	i = 0;
	while (args_first[i] && args_second[i])
	{
		if (ft_strlen(args_first[i]) != ft_strlen(args_second[i]))
			return (1);
		if (ft_strncmp(args_first[i], args_second[i], ft_strlen(args_first[i])))
			return (1);
		i++;
	}
	return (0);
}
