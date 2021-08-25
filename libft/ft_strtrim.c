/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:42:36 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/02 17:04:26 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_index(char c, const char *set)
{
	int	i;

	i = 0;
	while (*(set + i) != c && *(set + i) != '\0')
		i++;
	if (*(set + i) == c)
		return (i);
	return (-1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*src;
	int		start;
	int		last;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	last = (int)ft_strlen(s1);
	while (*(s1 + start) != '\0' && ft_find_index(*(s1 + start), set) >= 0)
		start++;
	while (s1 + last != s1 && ft_find_index(*(s1 + last), set) >= 0)
		last--;
	if (start > last)
	{
		src = malloc(sizeof(*src) * 1);
		*src = '\0';
		return (src);
	}
	src = malloc(sizeof(*src) * (last - start + 2));
	if (src == NULL)
		return (NULL);
	src = ft_memcpy(src, s1 + start, last - start + 1);
	*(src + last - start + 1) = '\0';
	return (src);
}
