/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:44:23 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/02 18:10:51 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substr_malloc(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (ft_strlen(s) >= start + len && len + 1 != 0)
		sub = malloc(sizeof(*sub) * (len + 1));
	else if (start <= ft_strlen(s))
		sub = malloc(sizeof(*sub) * (ft_strlen(s) - start + 1));
	else
		sub = malloc(sizeof(*sub) * 1);
	return (sub);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	sub = ft_substr_malloc(s, start, len);
	if (sub == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	while (len-- > 0)
	{
		if (*(s + i + start) == '\0' && len != 0)
		{
			*(sub + i) = '\0';
			return (sub);
		}
		else
			*(sub + i) = *(s + i + start);
		i++;
	}
	*(sub + i) = '\0';
	return (sub);
}
