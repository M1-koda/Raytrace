/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:56:45 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 11:59:05 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_bonus.h"
#include "input_bonus.h"

void	free_error_exit(int err, t_all *all)
{
	free_all(all);
	error_exit(err);
}

int	calc_digit_number(int	digit)
{
	int	num;

	num = 1;
	while (digit / (int)pow(10, num) != 0)
		num++;
	return (num);
}

int	calc_dp_len(char **src, int thresh)
{
	int	len;

	len = 0;
	if (thresh <= 0)
		thresh = INT_MAX;
	while (src[len])
	{
		len++;
		if (len > thresh)
			return (-1);
	}
	return (len);
}

void	d_free(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		free(src[i++]);
	free(src);
}
