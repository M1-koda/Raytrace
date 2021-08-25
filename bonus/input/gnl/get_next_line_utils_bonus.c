/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:49:38 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:08:16 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../../includes/all_bonus.h"

size_t	ft_strlen_g(const char *src)
{
	size_t	len;

	len = 0;
	if (src == NULL)
		return (len);
	while (*(src + len) != '\0')
		len++;
	return (len);
}

char	*ft_substr_g(const char *src, unsigned int start, size_t len)
{
	char				*result;
	size_t				s_l;
	unsigned int		i;

	if (src == NULL)
		return (NULL);
	s_l = ft_strlen_g(src);
	if (len + (size_t)start > s_l)
		result = malloc(sizeof(char) * (s_l - start + 1));
	else if (len + 1 > 0)
		result = malloc(sizeof(char) * (len + 1));
	else
		result = NULL;
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len && src[start + i] != '\0')
	{
		result[i] = *(src + start + i);
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin_g(const char *s1, const char *s2)
{
	char			*result;
	size_t			len;
	size_t			s1_l;
	size_t			i;

	if (s2 == NULL)
		return (free_return_null((void *)s1));
	s1_l = ft_strlen_g(s1);
	len = s1_l + ft_strlen_g(s2);
	result = malloc(sizeof(*result) * (len + 1));
	i = -1;
	while (++i < len && result != NULL)
	{
		if (i < s1_l)
			result[i] = *(s1 + i);
		else
			result[i] = *(s2 + i - s1_l);
	}
	if (result != NULL)
		result[i] = '\0';
	free((void *)s1);
	free((void *)s2);
	return (result);
}
