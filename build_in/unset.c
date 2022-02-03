/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:36:25 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(char **args, char ***env_array)
{
	int		i;
	int		j;
	char	**tmp;

	if (ft_arr_len(args) <= 1)
		return ;
	else
	{
		tmp = *env_array;
		*env_array = ft_calloc(ft_arr_len(tmp) + 1, sizeof (char *));
		i = 0;
		j = -1;
		while ((tmp)[++j])
		{
			if (!(ft_strncmp(tmp[j], args[1], ft_strlen(tmp[j])
						- ft_strlen(ft_strchr(tmp[j], '='))) == 0
					&& ft_strlen(tmp[j]) - ft_strlen(ft_strchr(tmp[j], '='))
					== ft_strlen(args[1])))
				(*env_array)[i++] = ft_strdup(tmp[j]);
		}
		(*env_array)[i] = NULL;
		free_all(tmp);
	}
	ft_call_export(args, env_array, 0);
}
