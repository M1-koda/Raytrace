/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:12:20 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/02 17:23:15 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_list;

	n_list = malloc(sizeof(*n_list) * 1);
	if (n_list == NULL)
		return (NULL);
	n_list->content = content;
	n_list->next = NULL;
	return (n_list);
}
