/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:30:09 by ykohda            #+#    #+#             */
/*   Updated: 2020/11/09 01:55:46 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s_c;
	int		i;

	i = 0;
	s_c = malloc(sizeof(*s_c) * (ft_strlen(s1) + 1));
	if (s_c == NULL)
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		*(s_c + i) = *(s1 + i);
		i++;
	}
	*(s_c + i) = '\0';
	return (s_c);
}
