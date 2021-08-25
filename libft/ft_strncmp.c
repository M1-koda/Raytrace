/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:37:56 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/02 17:06:24 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int					result;
	const unsigned char	*s1_c;
	const unsigned char	*s2_c;

	result = 0;
	s1_c = (const unsigned char *)s1;
	s2_c = (const unsigned char *)s2;
	while (n > 0 && *s1_c != '\0' && *s2_c != '\0')
	{
		if (*s1_c != *s2_c)
			break ;
		s1_c++;
		s2_c++;
		n--;
	}
	if (n == 0)
		result = 0;
	else
		result = *s1_c - *s2_c;
	return (result);
}
