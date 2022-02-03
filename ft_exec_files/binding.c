/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:00:09 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/19 17:34:34 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	ft_count_args(char **args)
{
	int	count;

	count = 0;
	if (args)
		while (args[count])
			count++;
	return (count);
}

static void	ft_error(char **bind_args)
{
	if (NULL == bind_args)
	{
		write(2, "malloc error in ft_binding_args\n", 32);
		exit(1);
	}
}

static void	ft_what_exactly_free(char **args_first,
			char **args_second, int flag)
{
	if (args_first && flag == 0)
		ft_free(args_first);
	if (args_second && flag == 1)
		ft_free(args_second);
}

char	**ft_binding_args(char **args_first, char **args_second, int flag)
{
	int		count_first;
	int		count_second;
	int		i;
	int		j;
	char	**bind_args;

	count_first = ft_count_args(args_first);
	count_second = ft_count_args(args_second);
	if (count_second < 2)
		return (args_first);
	bind_args = (char **)malloc(sizeof(char *)
			* (count_first + count_second + 1));
	ft_error(bind_args);
	i = -1;
	while (++i < count_first)
		bind_args[i] = ft_strdup(args_first[i]);
	j = 1;
	if (!args_first)
		j = 0;
	while (j < count_second)
		bind_args[i++] = ft_strdup(args_second[j++]);
	bind_args[i] = NULL;
	ft_what_exactly_free(args_first, args_second, flag);
	return (bind_args);
}
