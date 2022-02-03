/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:44:35 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		size;

	size = 0;
	while (*(s1 + size))
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (NULL == ret)
		return (NULL);
	size = 0;
	while (*(s1 + size))
	{
		*(ret + size) = *(s1 + size);
		size++;
	}
	*(ret + size) = '\0';
	return (ret);
}
