/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:44:10 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_logic(void *dst, const void *src, size_t len)
{
	size_t	counter;
	void	*destination;
	void	*sourse;

	counter = 0;
	if (src > dst)
	{
		while (counter < len)
		{
			((unsigned char *)dst)[counter] = ((unsigned char *)src)[counter];
			counter++;
		}
	}
	else
	{
		destination = dst + (len - 1);
		sourse = (void *)src + (len - 1);
		while (counter < len)
		{
			*(unsigned char *)destination = *(unsigned char *)sourse;
			destination--;
			sourse--;
			counter++;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!src && !dst)
		return (dst);
	ft_logic(dst, src, len);
	return (dst);
}
