/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:45:00 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	saver;
	int	len;

	saver = -1;
	len = 0;
	while (*(s + len))
	{
		if (*(s + len) == (const char)c)
			saver = len;
		len++;
	}
	if (*(s + len) == (const char)c)
		saver = len;
	if (saver != -1)
		return ((char *)(s + saver));
	else
		return (NULL);
}
