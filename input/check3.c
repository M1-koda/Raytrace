/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:49:12 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 06:07:25 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"
#include "input.h"

int	tr_check(char **src)
{
	if (calc_dp_len(src, 5) != 5)
		return (0);
	if (ft_strncmp(src[0], "tr", ft_strlen(src[0])))
		return (0);
	if (!check_xyz_rgb(src[1], 1))
		return (0);
	if (!check_xyz_rgb(src[2], 1))
		return (0);
	if (!check_xyz_rgb(src[3], 1))
		return (0);
	if (!check_xyz_rgb(src[4], 0))
		return (0);
	return (1);
}

int	sq_check(char **src)
{
	if (calc_dp_len(src, 5) != 5)
		return (0);
	if (ft_strncmp(src[0], "sq", ft_strlen(src[0])))
		return (0);
	if (!check_xyz_rgb(src[1], 1))
		return (0);
	if (!check_xyz_rgb(src[2], 1))
		return (0);
	if (!ft_isdouble(src[3]))
		return (0);
	if (!check_xyz_rgb(src[4], 0))
		return (0);
	return (1);
}
