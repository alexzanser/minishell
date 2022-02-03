/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:45:07 by                   #+#    #+#             */
/*   Updated: 2021/10/13 14:34:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	count;
	size_t	len_substr;
	size_t	chars;

	if (!s)
		return (NULL);
	count = 0;
	chars = 0;
	len_substr = 0;
	while (s[start + len_substr] && len_substr < len)
		len_substr++;
	substr = (char *)malloc(sizeof(char) * (len_substr + 1));
	if (NULL == substr)
		return (NULL);
	while (s[count])
	{
		if (count >= start && chars < len_substr)
			substr[chars++] = s[count];
		count++;
	}
	substr[chars] = '\0';
	return (substr);
}
