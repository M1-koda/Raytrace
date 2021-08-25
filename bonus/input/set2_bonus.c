/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:50:34 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:05:50 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_bonus.h"
#include "input_bonus.h"

int	create_pl(char **src, t_all *all)
{
	t_obj	*result;

	result = create_obj(all->objs);
	if (!result)
		return (1);
	result->name = ft_strdup(src[0]);
	result->point = create_xyz(src[1]);
	result->norm = create_xyz(src[2]);
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
	result->norm = create_xyz(src[2]);
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
	result->norm = create_xyz(src[2]);
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
