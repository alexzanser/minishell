/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_funcs_2_quotes_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:40:08 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_remove_quotes(void *content)
{
	char	*str;
	int		i;

	str = (char *)content;
	i = -1;
	while (str[++i + 1])
		str[i] = str[i + 1];
	str[i - 1] = '\0';
}

char	*ft_end_of_var(char *content)
{
	content++;
	if (ft_isdigit(*content))
	{
		content++;
		return (content);
	}
	while (*content && !ft_is_space(*content) && *content != '\''
		&& *content != '\"' && (ft_isalpha(*content)
			|| ft_isdigit(*content) || *content == '_'))
	{
		content++;
	}
	if (*content == '?')
		content++;
	return (content);
}

void	ft_remove_bad_env(char **content, int pre_len, int var_len)
{
	char	*new_content;

	new_content = ft_calloc(pre_len + 1, sizeof(char));
	new_content = ft_memcpy(new_content, *content, pre_len);
	new_content = ft_strjoin2(&new_content, *content + pre_len + var_len + 1);
	ft_bzero(*content, ft_strlen(*content) + 1);
	*content = ft_strjoin2(content, new_content);
	free(new_content);
}

void	ft_remove_correct_env(char **content, char **envp, int i)
{
	int		pre_len;
	int		var_len;
	char	*new_content;
	int		post_len;

	pre_len = ft_strlen(*content) - ft_strlen(ft_strchr(*content, '$'));
	post_len = ft_strlen(ft_end_of_var(ft_strchr(*content, '$')));
	var_len = ft_strlen(*content) - pre_len - post_len - 1;
	new_content = ft_calloc(pre_len + 1, sizeof (char));
	new_content = ft_memcpy(new_content, *content, pre_len);
	new_content = ft_strjoin2(&new_content, ft_strchr(envp[i], '=') + 1);
	new_content = ft_strjoin2(&new_content, *content + pre_len + var_len + 1);
	ft_bzero(*content, ft_strlen(*content) + 1);
	*content = ft_strjoin2(content, new_content);
	free(new_content);
}

void	ft_replace_by_envp(char **content, char**envp)
{
	int		i;
	int		pre_len;
	int		var_len;
	int		post_len;

	i = -1;
	pre_len = ft_strlen(*content) - ft_strlen(ft_strchr(*content, '$'));
	post_len = ft_strlen(ft_end_of_var(ft_strchr(*content, '$')));
	var_len = ft_strlen(*content) - pre_len - post_len - 1;
	while (envp[++i] && ft_strchr(*content, '$'))
	{
		if (ft_strchr(*content, '$')
			&& !ft_strncmp(envp[i], ft_strchr(*content, '$') + 1, var_len)
			&& var_len == (int)(ft_strlen(envp[i]) - ft_strlen(
				ft_strchr(envp[i], '='))))
		{
			ft_remove_correct_env(content, envp, i);
			return ;
		}
	}
	if (ft_is_valid_dollar(*content))
		ft_remove_bad_env(content, pre_len, var_len);
}
