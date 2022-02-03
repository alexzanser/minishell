/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_funcs_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:38:41 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_all(char **result)
{
	int	j;

	j = 0;
	while (result[j])
	{
		free(result[j]);
		j++;
	}
	free(result);
}

void	free_all_exclude_head(char **result)
{
	int	j;

	j = 0;
	while (result[j])
	{
		free(result[j]);
		j++;
	}
}

char	*ft_find_path(void *content, char *path)
{
	char	**paths;
	char	*path_result;
	int		i;

	i = 0;
	if (path)
	{
		paths = ft_split(path, ':');
		while (paths[i])
		{
			paths[i] = ft_strjoin2(&paths[i], "/");
			path_result = ft_strjoin(paths[i], (char *) content);
			if (access(path_result, F_OK) == 0)
			{
				free_all(paths);
				return (path_result);
			}
			else
				free(path_result);
			i++;
		}
		free_all(paths);
	}
	return (NULL);
}

int	ft_set_path(t_arg *func_l, char *path, char ***envp)
{
	int	flag;

	flag = 0;
	while (func_l)
	{
		func_l->path = ft_find_path(func_l->content, path);
		if (!func_l->path && !ft_is_pipe_or_redir(func_l->content)
			&& !ft_is_built_int(func_l->content)
			&& !ft_is_pipe_or_redir(func_l->content) && !func_l->prev)
		{
			ft_call_export(func_l->args, envp, 127);
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(func_l->content, 2);
			ft_putstr_fd(" : command not found\n", 2);
			flag = 1;
		}
		func_l = func_l->next;
	}
	return (flag);
}

char	*ft_strjoin2(char **s1, char *s2)
{
	char	*s_start;
	char	*s1_start;
	char	*s;

	s = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	s_start = s;
	s1_start = *s1;
	while (**s1)
		*(s++) = *((*s1)++);
	while (*s2 && *s2 != '\n')
		*s++ = *s2++;
	if (*s2 == '\n')
		*(s++) = '\n';
	*s = '\0';
	free((void *) s1_start);
	return (s_start);
}
