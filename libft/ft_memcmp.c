/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:17:47 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/02 18:07:12 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;
	size_t				i;

	i = 0;
	src1 = s1;
	src2 = s2;
	while (n > i)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		src1++;
		src2++;
		i++;
	}
	return (0);
}
