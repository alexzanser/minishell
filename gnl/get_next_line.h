/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:00:00 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/08 14:31:58 by kmercy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100
# include <unistd.h>
# include "stdlib.h"
# include <fcntl.h>

void	ft_bzero_gnl(void *s, size_t n);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char **s1, char *s2);
char	*ft_strchr_gnl(const char *str, int ch);
int		find_pos_of_newline(const char *str);
void	buffer_change(char *str, int pos);
char	*get_next_line(int fd);
#endif
