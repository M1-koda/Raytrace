/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:36:48 by ykohda            #+#    #+#             */
/*   Updated: 2020/11/10 23:44:40 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ch_s;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = (int)ft_strlen(s);
	ch_s = malloc(sizeof(*ch_s) * (len + 1));
	if (ch_s == NULL)
		return (NULL);
	i = 0;
	ch_s[len] = '\0';
	while (*(s + i) != '\0')
	{
		ch_s[i] = f((unsigned int)i, *(s + i));
		i++;
	}
	return (ch_s);
}
