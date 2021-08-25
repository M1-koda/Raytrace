/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:22:55 by ykohda            #+#    #+#             */
/*   Updated: 2020/11/10 23:43:41 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n / 10 == 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -1 * n;
		}
		c = '0' + n;
		ft_putchar_fd(c, fd);
	}
	else
	{
		if (n < 0)
			c = '0' + (-1) * (n % 10);
		else
			c = '0' + n % 10;
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(c, fd);
	}
}
