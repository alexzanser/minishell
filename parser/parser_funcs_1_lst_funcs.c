/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_funcs_1_lst_funcs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmercy <kmercy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:04:23 by kmercy            #+#    #+#             */
/*   Updated: 2021/12/19 13:50:37 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*ft_lst2_new(char *content)
{
	t_arg	*new;

	new = (t_arg *) malloc(sizeof(t_arg));
	if (!new)
		return (NULL);
	new->content = content;
	new->path = NULL;
	new->args = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lst2add_back(t_arg **lst, t_arg *new)
{
	t_arg	*cur;

	cur = *lst;
	if (!new)
		return ;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
	else
		*lst = new;
}

void	ft_lst2add_args(t_arg **lst, char **line)
{
	t_arg	*cur;

	cur = *lst;
	if (!line)
		return ;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->args = line;
	}
}

void	ft_show_lst(t_arg *lst)
{
	int	i;

	if (lst)
	{
		while (lst != NULL)
		{
			if (lst->content)
				printf("content: %s\n", lst->content);
			if (lst->path)
				printf("path: %s\n", lst->path);
			if (lst->args)
			{
				i = 0;
				printf("args: ");
				while (lst->args[i])
				{
					printf("%s ", lst->args[i]);
					i++;
				}
				printf("\n");
			}
			printf("-----------\n");
			lst = lst->next;
		}
	}
}

void	ft_free_lst(t_arg **lst)
{
	t_arg	*tmp;
	int		i;

	if (*lst)
	{
		while (*lst != NULL)
		{
			tmp = (*lst)->next;
			if ((*lst)->content)
				free((*lst)->content);
			if ((*lst)->path)
				free((*lst)->path);
			if ((*lst)->args)
			{
				i = -1;
				while (((*lst)->args)[++i])
					free((*lst)->args[i]);
				free((*lst)->args);
			}
			free(*lst);
			*lst = tmp;
		}
	}
}
