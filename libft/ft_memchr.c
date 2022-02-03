/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:43:58 by                   #+#    #+#             */
/*   Updated: 2021/10/13 14:21:56 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((unsigned char *)s);
		s++;
		n--;
	}
	if (n > 0 && *(unsigned char *)s == c)
		return ((unsigned char *)s);
	return (NULL);
}

/*
int main(void)
{
    char s[] = {1, 1, 2 ,3 ,4 ,5};

    printf("str:%s\n", s);
    printf("1:%s\n", (char *)memchr(s, 0, 5));
    printf("2:%s\n", (char *)memchr(s, 0, 1));
    printf("3:%s\n", (char *)memchr(s, 2, 3));
    printf("4:%s\n", (char *)memchr(s, 6, 10));
    printf("5:%s\n", (char *)memchr(s, 2 + 256, 3));
    printf("---------------------\n");
    printf("str:%s\n", s);
    printf("11111:%s\n", (char *)ft_memchr(s, 0, 5));
    printf("22222:%s\n", (char *)ft_memchr(s, 0, 1));
    printf("33333:%s\n", (char *)ft_memchr(s, 2, 3));
    printf("44444:%s\n", (char *)ft_memchr(s, 6, 10));
    printf("55555:%s\n", (char *)ft_memchr(s, 2 + 256, 3));
    return (0);
}*/
