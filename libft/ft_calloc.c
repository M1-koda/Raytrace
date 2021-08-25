/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:56:17 by ykohda            #+#    #+#             */
/*   Updated: 2020/11/12 01:06:18 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*src;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	src = malloc(count * size);
	if (src)
		ft_bzero(src, count * size);
	return (src);
}
