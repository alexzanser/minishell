/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:44:57 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count_h;
	size_t	count_ne;
	size_t	len_ne;

	count_h = 0;
	len_ne = 0;
	while (*(needle + len_ne))
		len_ne++;
	if (len_ne == 0)
		return ((char *) haystack);
	while (*(haystack + count_h) && count_h < len)
	{
		count_ne = 0;
		while (*(needle + count_ne))
		{
			if (*(needle + count_ne) != *(haystack + count_h + count_ne))
				break ;
			count_ne++;
		}
		if (count_ne == len_ne && count_h + count_ne <= len)
			return ((char *)(haystack + count_h));
		count_h++;
	}
	return (NULL);
}
