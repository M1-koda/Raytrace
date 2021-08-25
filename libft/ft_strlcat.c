/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:33:28 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/02 18:08:56 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_l;
	size_t	d_l;

	s_l = ft_strlen(src);
	d_l = ft_strlen(dst);
	if (dstsize <= d_l)
		return (s_l + dstsize);
	while (*dst != '\0')
		dst++;
	if (s_l + d_l + 1 < dstsize)
		ft_memcpy(dst, src, s_l + 1);
	else
	{
		ft_memcpy(dst, src, dstsize - d_l - 1);
		*(dst + dstsize - d_l - 1) = '\0';
	}
	return (s_l + d_l);
}
