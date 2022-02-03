/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_funcs_arrays.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:49:49 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_arr_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**ft_char_array_cpy(char **array)
{
	char	**new_array;
	int		i;

	new_array = ft_calloc(ft_arr_len(array) + 2, sizeof (char *));
	i = 0;
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	new_array[i] = ft_strdup("?=0");
	i++;
	new_array[i] = NULL;
	return (new_array);
}

char	**ft_add_args(char **old_arr, char *new_elem)
{
	int		i;
	char	**new_arr;

	i = 0;
	if (old_arr)
		new_arr = ft_calloc(ft_arr_len(old_arr) + 2, sizeof(char *));
	else
		new_arr = ft_calloc(1, sizeof(char *));
	while ((old_arr)[i])
	{
		new_arr[i] = ft_strdup(old_arr[i]);
		i++;
	}
	new_arr[i] = ft_strdup(new_elem);
	return (new_arr);
}

void	ft_args_control(t_arg **arg_l, char ***arr)
{
	char	**tmp;

	tmp = *arr;
	*arr = ft_add_args(*arr, (*arg_l)->content);
	free_all(tmp);
	(*arg_l) = (*arg_l)->next;
}
