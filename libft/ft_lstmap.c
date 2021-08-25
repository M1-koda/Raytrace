/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:11:18 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/02 18:12:42 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*start;

	if (lst == NULL)
		return (NULL);
	n_list = ft_lstnew(f(lst->content));
	lst = lst->next;
	start = n_list;
	while (lst != NULL)
	{
		n_list->next = ft_lstnew(f(lst->content));
		if (!n_list->next->content)
			del(n_list->next->content);
		lst = lst->next;
		n_list = n_list->next;
	}
	return (start);
}
