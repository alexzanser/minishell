/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:42:54 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	sig_quit_par(int signal)
{
	(void)signal;
	ft_putstr_fd("Quit: 3\n", 2);
}

void	ft_sig_parent(void)
{
	signal(SIGINT, sig_int_par);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_sig_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_sig_par_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, sig_quit_par);
}

void	sig_int_par(int signal)
{
	(void) signal;
	write(0, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
