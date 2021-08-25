/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:31:59 by ykohda            #+#    #+#             */
/*   Updated: 2020/11/10 17:23:31 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;
	size_t	s1_l;
	char	*str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_l = ft_strlen(s1);
	len = s1_l + ft_strlen(s2) + 1;
	str = malloc(sizeof(*str) * len);
	if (str == NULL)
		return (NULL);
	while (len > i)
	{
		if (s1_l > i)
			*(str + i) = *(s1 + i);
		else
			*(str + i) = *(s2 + i - s1_l);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
