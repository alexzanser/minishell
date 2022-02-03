/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:59:51 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/19 13:42:41 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char **s1, char *s2)
{
	char	*s_start;
	char	*s1_start;
	char	*s;

	s = malloc(sizeof(char) * (ft_strlen_gnl(*s1) + ft_strlen_gnl(s2) + 1));
	if (!s)
		return (NULL);
	s_start = s;
	s1_start = *s1;
	while (**s1)
		*(s++) = *((*s1)++);
	while (*s2 && *s2 != '\n')
		*s++ = *s2++;
	if (*s2 == '\n')
		*(s++) = '\n';
	*s = '\0';
	free((void *) s1_start);
	return (s_start);
}

int	find_pos_of_newline(const char *str)
{
	int	i;

	i = 0;
	if (ft_strchr_gnl(str, '\n') != NULL)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				break ;
			i++;
		}
	}
	else
		while (str[i])
			i++;
	return (i);
}

char	*get_next_line_read(char *line, char *buffer, int fd)
{
	int	read_result;

	read_result = 1;
	while (read_result > 0 && line)
	{
		if (read_result == -1)
			return (NULL);
		if (ft_strlen_gnl(buffer) == 0)
			read_result = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin_gnl(&line, buffer);
		if (ft_strchr_gnl(buffer, '\n') == NULL)
			ft_bzero_gnl(buffer, BUFFER_SIZE + 1);
		else
		{
			buffer_change(&*buffer, find_pos_of_newline(buffer));
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE
		*((BUFFER_SIZE > 0) - (BUFFER_SIZE < 0)) + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = (char *) malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	ft_bzero_gnl(line, BUFFER_SIZE + 1);
	line = get_next_line_read(line, buffer, fd);
	if (ft_strlen_gnl(line) == 0 || !line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
