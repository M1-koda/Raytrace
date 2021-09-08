/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:50:34 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 06:24:13 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"
#include "input.h"

int	create_pl(char **src, t_all *all)
{
	t_obj	*result;

	result = create_obj(all->objs);
	if (!result)
		return (1);
	result->name = ft_strdup(src[0]);
	result->point = create_xyz(src[1]);
	result->norm = create_xyz_norm(src[2]);
	result->TRGB = create_RGB(src[3]);
	if (result->TRGB == color_trgb(255, 0, 0, 0) || !(result->point) || \
		!(result->norm))
		return (1);
	if (!all->objs)
		all->objs = result;
	return (0);
}

int	create_cy(char **src, t_all *all)
{
	t_obj	*result;

	result = create_obj(all->objs);
	if (!result)
		return (1);
	result->name = ft_strdup(src[0]);
	result->point = create_xyz(src[1]);
	result->norm = create_xyz_norm(src[2]);
	result->diameter = ft_atod(src[3]);
	result->height = ft_atod(src[4]);
	result->TRGB = create_RGB(src[5]);
	if (result->TRGB == color_trgb(255, 0, 0, 0) || !(result->point) || \
	!(result->norm) || result->diameter <= 0 || result->height <= 0)
		return (1);
	if (!all->objs)
		all->objs = result;
	return (0);
}

int	create_cn(char **src, t_all *all)
{
	t_obj	*result;

	result = create_obj(all->objs);
	if (!result)
		return (1);
	result->name = ft_strdup(src[0]);
	result->point = create_xyz(src[1]);
	result->norm = create_xyz_norm(src[2]);
	result->diameter = ft_atod(src[3]);
	result->height = ft_atod(src[4]);
	result->TRGB = create_RGB(src[5]);
	if (result->TRGB == color_trgb(255, 0, 0, 0) || !(result->point) || \
	!(result->norm) || result->diameter <= 0 || result->height <= 0)
		return (1);
	if (!all->objs)
		all->objs = result;
	return (0);
}

int	create_tr(char **src, t_all *all)
{
	t_obj		*result;
	t_vector	*tmp;
	t_vector	*tmp2;

	result = create_obj(all->objs);
	if (!result)
		return (1);
	result->name = ft_strdup(src[0]);
	result->point = create_xyz(src[1]);
	result->point2 = create_xyz(src[2]);
	tmp = create_xyz(src[2]);
	result->point3 = create_xyz(src[3]);
	tmp2 = create_xyz(src[3]);
	calc_minus_vec(tmp, result->point);
	calc_minus_vec(tmp2, result->point);
	result->norm = calc_cross_product(tmp, tmp2);
	calc_mply_vec(result->norm, 1 / calc_vector_len(result->norm));
	result->TRGB = create_RGB(src[4]);
	free(tmp);
	free(tmp2);
	if (result->TRGB == color_trgb(255, 0, 0, 0) || !(result->point) || \
		!(result->norm))
		return (1);
	if (!all->objs)
		all->objs = result;
	return (0);
}

int	create_sq(char **src, t_all *all)
{
	t_obj		*result;

	result = create_obj(all->objs);
	if (!result)
		return (1);
	result->name = ft_strdup(src[0]);
	result->point = create_xyz(src[1]);
	result->norm = create_xyz_norm(src[2]);
	result->diameter = ft_atod(src[3]);
	result->TRGB = create_RGB(src[4]);
	if (result->TRGB == color_trgb(255, 0, 0, 0) || !(result->point) || \
		!(result->norm))
		return (1);
	if (!all->objs)
		all->objs = result;
	return (0);
}
