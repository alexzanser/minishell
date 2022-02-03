/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_funcs_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:05:32 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_pipe_or_redir(void *cont)
{
	char	*content;

	content = (char *) cont;
	if (content)
	{
		if (!ft_strncmp(content, "|", 1) && ft_strlen(content) == 1)
			return (1);
		else if (!ft_strncmp(content, ">", 1) && ft_strlen(content) == 1)
			return (2);
		else if (!ft_strncmp(content, "<", 1) && ft_strlen(content) == 1)
			return (3);
		else if (!ft_strncmp(content, ">>", 1) && ft_strlen(content) == 2)
			return (4);
		else if (!ft_strncmp(content, "<<", 1) && ft_strlen(content) == 2)
			return (5);
		else
			return (0);
	}
	return (0);
}

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	ft_next_other(char *arg_str)
{
	int	i;

	i = -1;
	while (arg_str[++i])
	{
		if ((arg_str[i] == ' ' || arg_str[i] == '\''
				|| arg_str[i] == '\"' || arg_str[i] == '|'
				|| arg_str[i] == '<' || arg_str[i] == '>') && i != 0)
		{
			return (i);
		}
	}
	return (i);
}

int	ft_next_space_pipe(char *arg_str)
{
	int	i;

	i = -1;
	while (arg_str[++i])
	{
		if ((arg_str[i] == ' ' || arg_str[i] == '|') && i != 0)
		{
			return (i);
		}
	}
	return (i);
}

int	ft_correct_number(char *number)
{
	char	*saver;

	saver = number;
	if (*saver == '-' || *saver == '+')
		saver++;
	while (*saver)
	{
		if (ft_isdigit(*saver) == 0)
			return (1);
		saver++;
	}
	return (0);
}
