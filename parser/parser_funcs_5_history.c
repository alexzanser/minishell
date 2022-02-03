/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:54:16 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/20 14:14:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_read_history(int history_fd)
{
	char	*history_line;

	history_line = get_next_line(history_fd);
	while (history_line != NULL)
	{
		history_line[ft_strlen(history_line) - 1] = '\0';
		add_history(history_line);
		free(history_line);
		history_line = get_next_line(history_fd);
	}
}

void	ft_write_history(int history_fd, char *line, int argc, char **argv)
{
	(void) argc;
	(void ) argv;
	write(history_fd, line, ft_strlen(line));
	write(history_fd, "\n", 1);
	add_history(line);
}
