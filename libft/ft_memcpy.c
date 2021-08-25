/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:18:49 by ykohda            #+#    #+#             */
/*   Updated: 2020/11/09 01:33:02 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*c_dst;
	const char	*c_src;
	size_t		i;

	i = 0;
	if (dst == src)
		return (dst);
	c_dst = dst;
	c_src = src;
	while (n > i)
	{
		*(c_dst + i) = *(c_src + i);
		i++;
	}
	return (dst);
}
