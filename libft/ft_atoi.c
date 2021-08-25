/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:51:37 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/02 17:22:06 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isover(int sign, unsigned long int result,
		const char *str, int i)
{
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (sign > 0 && result != 0)
			if ((unsigned long int)LONG_MAX / result < 10)
				return (-1);
		if (sign < 0 && result != 0)
			if (-1 * (unsigned long int)LONG_MIN / result < 10)
				return (0);
		result = result * 10;
		result = result + str[i++] - '0';
	}
	if (result > (unsigned long int)LONG_MAX && sign > 0)
		return (-1);
	else if (result > -1 * (unsigned long int)LONG_MIN && sign < 0)
		return (0);
	else
		return ((int)sign * result);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		sign = -1;
	else if (str[i] == '+')
		sign = 1;
	else if ('0' <= str[i] && str[i] <= '9')
		i--;
	else
		return (result);
	i++;
	return (ft_isover(sign, result, str, i));
}
