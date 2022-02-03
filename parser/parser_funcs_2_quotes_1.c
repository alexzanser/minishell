/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_funcs_2_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:04:36 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/21 13:01:08 by kmercy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_valid_dollar(char *content)
{
	while (*content)
	{
		if (*content == '$' && (ft_isalpha(*(content + 1))
				|| ft_isdigit(*(content + 1))
				|| *(content + 1) == '_' || *(content + 1) == '?'))
			return (1);
		content++;
	}
	return (0);
}

int	is_double_quote_main(char *content)
{
	int	i;

	i = -1;
	if (ft_strchr(content, '\"')
		&& ft_closed_quote(ft_strchr(content, '\"'))
		&& (ft_strchr(content, '\'')
			&& ft_closed_quote(ft_strchr(content, '\''))))
	{
		while (content[++i])
		{
			if (*content == '\'')
				return (0);
			if (*content == '\"')
				return (1);
		}
	}
	else if (ft_strchr(content, '\"')
		&& ft_closed_quote(ft_strchr(content, '\"')))
		return (1);
	return (0);
}

void	ft_handle_envps(t_arg *arg_l, char**envp)
{
	char	**content;

	while (arg_l != NULL)
	{
		content = &(arg_l->content);
		while (ft_strchr(*content, '\"') && ft_closed_quote(
				ft_strchr(*content, '\"')) && ft_is_valid_dollar(*content)
			&& is_double_quote_main(*content))
			ft_replace_by_envp(content, envp);
		while (!(ft_strchr(*content, '\'') && ft_closed_quote(
					ft_strchr(*content, '\''))) && ft_is_valid_dollar(*content))
			ft_replace_by_envp(content, envp);
		arg_l = arg_l->next;
	}
}

int	ft_closed_quote(char *arg_str)
{
	int	i;

	i = 0;
	while (arg_str[++i])
	{
		if ((arg_str[i] == '\'' && arg_str[0] == '\'')
			|| (arg_str[i] == '\"' && arg_str[0] == '\"'))
		{
			i++;
			return (i);
		}
	}
	return (0);
}

int	ft_pull(char *args_str, char **cur_arg, int n)
{
	*cur_arg = ft_calloc(n + 1, sizeof (char));
	if (!*cur_arg)
		return (0);
	ft_memcpy(*cur_arg, args_str, n);
	return (n);
}
