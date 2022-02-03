/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:44:43 by                   #+#    #+#             */
/*   Updated: 2021/10/12 15:13:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	counter;
	size_t	len_src;
	size_t	len_dst;

	counter = 0;
	len_src = ft_strlen((char *)src);
	len_dst = ft_strlen((char *)dst);
	if (dstsize <= len_dst || dstsize == 0)
		return (len_src + dstsize);
	while (counter < dstsize - len_dst - 1 && src[counter] != '\0')
	{
		dst[len_dst + counter] = src[counter];
		counter++;
	}
	dst[len_dst + counter] = '\0';
	return (len_src + len_dst);
}
