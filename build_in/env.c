/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:06:59 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_arr_sort(char ***arr_copy)
{
	char	*tmp;
	int		j;
	int		i;

	i = -1;
	while ((*arr_copy)[++i])
	{
		j = i - 1;
		while ((*arr_copy)[++j])
		{
			if (ft_strncmp((*arr_copy)[i], (*arr_copy)[j],
			ft_strlen((*arr_copy)[i])) > 0)
			{
				tmp = (*arr_copy)[i];
				(*arr_copy)[i] = (*arr_copy)[j];
				(*arr_copy)[j] = tmp;
			}
		}
	}
}

void	ft_env(char **argc, char ***env_array)
{
	int		i;
	char	**arr_copy;

	arr_copy = ft_char_array_cpy(*env_array);
	i = -1;
	ft_arr_sort(&arr_copy);
	(void)argc;
	while (arr_copy[++i])
	{
		if (arr_copy[i][0] != '?')
		{
			ft_putstr_fd(arr_copy[i], 1);
			ft_putchar_fd('\n', 1);
		}
	}
	free_all(arr_copy);
}
