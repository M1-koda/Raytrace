/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:49:12 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 06:07:25 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"
#include "input.h"

int	C_check(char **src)
{
	if (calc_dp_len(src, 4) != 4)
		return (0);
	if (ft_strncmp(src[0], "C", ft_strlen(src[0])))
		return (0);
	if (!check_xyz_rgb(src[1], 1))
		return (0);
	if (!check_xyz_rgb(src[2], 1))
		return (0);
	if (!ft_isdouble(src[3]))
		return (0);
	return (1);
}

int	sp_check(char **src)
{
	if (calc_dp_len(src, 4) != 4)
		return (0);
	if (ft_strncmp(src[0], "sp", ft_strlen(src[0])))
		return (0);
	if (!check_xyz_rgb(src[1], 1))
		return (0);
	if (!ft_isdouble(src[2]))
		return (0);
	if (!check_xyz_rgb(src[3], 0))
		return (0);
	return (1);
}

int	pl_check(char **src)
{
	if (calc_dp_len(src, 4) != 4)
		return (0);
	if (ft_strncmp(src[0], "pl", ft_strlen(src[0])))
		return (0);
	if (!check_xyz_rgb(src[1], 1))
		return (0);
	if (!check_xyz_rgb(src[2], 1))
		return (0);
	if (!check_xyz_rgb(src[3], 0))
		return (0);
	return (1);
}

int	cy_check(char **src)
{
	if (calc_dp_len(src, 6) != 6)
		return (0);
	if (ft_strncmp(src[0], "cy", ft_strlen(src[0])))
		return (0);
	if (!check_xyz_rgb(src[1], 1))
		return (0);
	if (!check_xyz_rgb(src[2], 1))
		return (0);
	if (!ft_isdouble(src[3]))
		return (0);
	if (!ft_isdouble(src[4]))
		return (0);
	if (!check_xyz_rgb(src[5], 0))
		return (0);
	return (1);
}

int	cn_check(char **src)
{
	if (calc_dp_len(src, 6) != 6)
		return (0);
	if (ft_strncmp(src[0], "cn", ft_strlen(src[0])))
		return (0);
	if (!check_xyz_rgb(src[1], 1))
		return (0);
	if (!check_xyz_rgb(src[2], 1))
		return (0);
	if (!ft_isdouble(src[3]))
		return (0);
	if (!ft_isdouble(src[4]))
		return (0);
	if (!check_xyz_rgb(src[5], 0))
		return (0);
	return (1);
}
