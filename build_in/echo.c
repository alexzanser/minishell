/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:15:19 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/19 14:31:54 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **argv, char ***envp)
{
	int	flag;
	int	i;
	int	argc;

	i = 0;
	flag = 0;
	(void)envp;
	argc = count_argv(argv);
	if (ft_arr_len(argv) > 1)
	{
		while (!ft_strncmp(argv[++i], "-n", 3))
			flag++;
		while (i != argc)
		{
			write(1, argv[i], ft_strlen(argv[i]));
			i++;
			if (i != argc)
				write(1, " ", 1);
		}
		if (flag == 0)
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	ft_call_export(argv, envp, 0);
}
