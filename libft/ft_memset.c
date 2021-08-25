/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:20:58 by ykohda            #+#    #+#             */
/*   Updated: 2020/11/08 00:21:02 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*uc_b;
	unsigned char	uc_c;

	i = 0;
	uc_b = (unsigned char *)b;
	uc_c = (unsigned char)c;
	while (len > i)
		*(uc_b + i++) = uc_c;
	return (b);
}
