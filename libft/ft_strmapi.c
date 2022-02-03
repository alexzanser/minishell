/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:44:52 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*ans;
	int		count;

	count = 0;
	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == ans)
		return (NULL);
	while (*(s + count))
	{
		*(ans + count) = f(count,*(s + count));
		count++;
	}
	*(ans + count) = '\0';
	return (ans);
}
