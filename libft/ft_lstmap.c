/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:43:49 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*ans_saver;

	if (!lst || !f)
		return (NULL);
	ans = (t_list *)malloc(sizeof(t_list));
	if (NULL == ans)
		return (NULL);
	ans_saver = ans;
	while (lst)
	{
		ans->next = ft_lstnew(f(lst->content));
		if (NULL == ans->next)
		{
			ft_lstclear(&(ans_saver->next), del);
			return (NULL);
		}
		ans = ans->next;
		lst = lst->next;
	}
	return (ans_saver->next);
}
