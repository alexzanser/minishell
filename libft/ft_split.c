/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:44:29 by                   #+#    #+#             */
/*   Updated: 2021/11/16 14:48:35 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len_word(char const *str, char c)
{
	int	size;

	size = 0;
	while (*str && *str != c)
	{
		size++;
		str++;
	}
	return (size);
}

static int	ft_words_counter(char const *s, char c)
{
	int	count_words;
	int	counter;

	count_words = 0;
	counter = 0;
	while (*(s + counter))
	{
		if (counter == 0 && *(s + counter) != c)
			count_words++;
		if (counter != 0 && *(s + counter) != c && *(s + counter - 1) == c)
			count_words++;
		counter++;
	}
	return (count_words);
}

static int	ft_logic(char **ans, char const *s, char c, int len_s)
{
	int		counter;
	int		i;
	int		len_word;

	i = 0;
	counter = 0;
	while (counter < len_s)
	{
		if (*(s + counter) != c)
		{
			len_word = ft_len_word((s + counter), c);
			ans[i] = ft_substr((s + counter), 0, len_word);
			if (NULL == ans[i])
			{
				while (i > 0)
					free(ans[--i]);
				return (-1);
			}
			counter += len_word;
			i++;
		}
		counter++;
	}
	ans[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;

	if (!s)
		return (NULL);
	ans = (char **)malloc(sizeof(char *) * (ft_words_counter(s, c) + 1));
	if (NULL == ans)
		return (NULL);
	if (ft_logic(ans, s, c, ft_strlen((char *)s)) == -1)
	{
		free(ans);
		return (NULL);
	}
	return (ans);
}

//#include <stdio.h>
//int main()
//{
//    char **test;
//    int i = 0;
//    test = ft_split("qwe qwe    qwe rrr", ' ');
//    while (test[i])
//        printf("str = %s\n", test[i++]);
//    return (0);
//}
