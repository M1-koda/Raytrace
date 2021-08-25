/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:27:34 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 10:12:25 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_strings(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*(s + i) != c)
		j++;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c && *(s + i + 1) != c && \
		*(s + i + 1) != '\0')
			j++;
		i++;
	}
	return (j);
}

static char	*ft_strndup(const char *s1, int n)
{
	char	*s_c;
	int		i;

	i = 0;
	if (s1 == NULL || *s1 == '\0')
	{
		s_c = malloc(sizeof(*s_c) * 1);
		*s_c = '\0';
		return (s_c);
	}
	s_c = malloc(sizeof(*s_c) * (n + 1));
	if (s_c == NULL)
		return (NULL);
	while (*(s1 + i) != '\0' && n > i)
	{
		*(s_c + i) = *(s1 + i);
		i++;
	}
	*(s_c + i) = '\0';
	return (s_c);
}

static char	**free_all_null(char **srcs)
{
	int	i;

	i = 0;
	while (*(srcs + i))
		free(*(srcs + i++));
	free(srcs);
	return (NULL);
}

static char	**split_cnt(const char *s, char **srcs, char c)
{
	int	i;
	int	j;

	i = 0;
	while (*s != '\0')
	{
		j = 0;
		while (*(s + j) != c && *(s + j) != '\0')
			j++;
		if (j > 0)
		{
			*(srcs + i++) = ft_strndup(s, j);
			if (!*(srcs + i - 1))
				return (free_all_null(srcs));
			s = s + j;
		}
		else
			s = s + 1;
	}
	*(srcs + i) = NULL;
	return (srcs);
}

char	**ft_split(const char *s, char c)
{
	char	**srcs;

	if (s == NULL)
		return (NULL);
	srcs = (char **)malloc(sizeof(*srcs) * (ft_count_strings(s, c) + 1));
	if (srcs == NULL)
		return (NULL);
	srcs = split_cnt(s, srcs, c);
	return (srcs);
}
