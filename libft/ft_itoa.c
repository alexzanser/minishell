/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:43:24 by                   #+#    #+#             */
/*   Updated: 2021/12/19 14:00:20 by eveiled          ###   ########.fr       */
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

static int	ft_count_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_logic(int n, int razr, char *ans)
{
	long int	n_l;

	n_l = n;
	if (n_l < 0)
	{
		*ans = '-';
		ans++;
		n_l *= -1;
	}
	if (n_l == 0)
	{
		*ans = '0';
		ans++;
	}
	while (razr != 0)
	{
		*ans = n_l / razr + '0';
		n_l = n_l % razr;
		razr = razr / 10;
		ans++;
	}
	*ans = '\0';
}

char	*ft_itoa(int n)
{
	long int			razr;
	int					len;
	char				*ans;

	razr = ft_count_razr(n);
	len = ft_count_len(n);
	ans = (char *)malloc(sizeof(char) * (len + 2));
	if (NULL == ans)
		return (NULL);
	ft_logic(n, razr, ans);
	return (ans);
}
