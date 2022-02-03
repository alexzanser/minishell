/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:44:21 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static long int	ft_count_razr(int n)
{
	long int	razr;

	razr = 1;
	while (n != 0)
	{
		razr = razr * 10;
		n = n / 10;
	}
	razr = razr / 10;
	return (razr);
}

static void	ft_logic(int fd, int n, int razr)
{
	long int	n_l;
	char		ch;

	n_l = n;
	if (n_l < 0)
	{
		write(fd, "-", 1);
		n_l *= -1;
	}
	if (n_l == 0)
	{
		write(fd, "0", 1);
	}
	while (razr != 0)
	{
		ch = n_l / razr + '0';
		write(fd, &ch, 1);
		n_l = n_l % razr;
		razr = razr / 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int			razr;

	razr = ft_count_razr(n);
	ft_logic(fd, n, razr);
}
