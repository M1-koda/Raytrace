/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:05:07 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/02 18:05:44 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digit++;
		n = n / 10;
	}
	return (digit);
}

static void	ft_write_num(char *num, int n, int digit)
{
	if (n == 0)
		num[0] = '0';
	while (n != 0 && digit != 0)
	{
		if (digit == 1 && n < 0)
		{
			num[0] = '-';
			num[1] = '0' + (-1) * n;
		}
		else if (n < 0)
			num[digit] = '0' + (-1) * (n % 10);
		else
			num[digit - 1] = '0' + n % 10;
		digit--;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*num;
	int		digit;

	digit = ft_count_digit(n);
	if (n < 0)
		num = malloc(sizeof(*num) * (digit + 2));
	else
		num = malloc(sizeof(*num) * (digit + 1));
	if (num == NULL)
		return (NULL);
	ft_write_num(num, n, digit);
	if (n < 0)
		num[digit + 1] = '\0';
	else
		num[digit] = '\0';
	return (num);
}
