/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:49:01 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 11:57:24 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_bonus.h"
#include "input_bonus.h"

int	check_xyz_rgb(char *src, int flag)
{
	char	**xyz;

	xyz = ft_split(src, ',');
	if (!xyz)
		return (0);
	if (calc_dp_len(xyz, 3) != 3)
		return (0);
	if (flag == 0 && (!ft_isint(xyz[0]) || !ft_isint(xyz[1]) || \
		!ft_isint(xyz[2])))
		return (0);
	if (flag == 1 && (!ft_isdouble(xyz[0]) || \
		!ft_isdouble(xyz[1]) || !ft_isdouble(xyz[2])))
		return (0);
	d_free(xyz);
	xyz = NULL;
	return (1);
}

//R L A ... and so on
int	R_check(char **src)
{
	if (calc_dp_len(src, 3) != 3)
		return (0);
	if (ft_strncmp(src[0], "R", ft_strlen(src[0])))
		return (0);
	if (!ft_isint(src[1]) || !ft_isint(src[2]))
		return (0);
	return (1);
}

int	A_check(char **src)
{
	if (calc_dp_len(src, 3) != 3)
		return (0);
	if (ft_strncmp(src[0], "A", ft_strlen(src[0])))
		return (0);
	if (!ft_isdouble(src[1]))
		return (0);
	if (!check_xyz_rgb(src[2], 0))
		return (0);
	return (1);
}

int	L_check(char **src)
{
	if (calc_dp_len(src, 4) != 4)
		return (0);
	if (ft_strncmp(src[0], "L", ft_strlen(src[0])))
		return (0);
	if (!check_xyz_rgb(src[1], 1))
		return (0);
	if (!ft_isdouble(src[2]))
		return (0);
	if (!check_xyz_rgb(src[3], 0))
		return (0);
	return (1);
}
