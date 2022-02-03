/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:14:22 by eveiled           #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(char **argv, char ***envp)
{
	(void)argv;
	(void)envp;
	ft_putstr_fd("exit\n", 1);
	if (argv[1] != NULL)
	{
		if (ft_arr_len(argv) > 2)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd("too many arguments\n", 2);
		}
		else if (ft_correct_number(argv[1]) == 0)
			exit(ft_atoi(argv[1]) % 256);
		else
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd("numeric argument required\n", 2);
			exit (255);
		}
	}
	else
		exit(0);
}
