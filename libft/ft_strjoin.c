/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:44:40 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		count;

	count = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1);
	if (NULL == join)
		return (NULL);
	while (*s1)
	{
		join[count] = *s1;
		s1++;
		count++;
	}
	while (*s2)
	{
		join[count] = *s2;
		s2++;
		count++;
	}
	join[count] = '\0';
	return (join);
}
