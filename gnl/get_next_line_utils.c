/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:00:03 by kmercy            #+#    #+#             */
/*   Updated: 2021/10/28 15:00:03 by kmercy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			((char *)s)[i] = '\0';
			i++;
		}
	}
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	size;

	size = 0;
	while (*s != '\0')
	{
		size++;
		s++;
	}
	return (size);
}

char	*ft_strchr_gnl(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == (char )ch)
			return ((char *)str);
		str++;
	}
	if (*str == (char )ch)
		return ((char *)str);
	return (NULL);
}

void	buffer_change(char *str, int pos)
{
	int	i;

	i = -1;
	while (str[(++i) + pos])
		str[i] = str[i + pos + 1];
	while (str[i])
		str[i++] = '\0';
}
