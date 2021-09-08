/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:50:26 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 06:27:23 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"
#include "input.h"

//obj light create & scn create
int	create_A(char **src, t_all *all)
{
	t_light	*result;

	if (!all->scn)
		all->scn = create_screen(NULL, NULL, NULL, 0);
	result = create_light(all->scn->lights);
	if (!result || !all->scn)
		return (1);
	result->name = ft_strdup(src[0]);
	result->range = ft_atod(src[1]);
	result->TRGB = create_RGB(src[2]);
	if (result->TRGB == color_trgb(255, 0, 0, 0))
		return (1);
	if (!all->scn->lights)
		all->scn->lights = result;
	return (0);
}

int	create_L(char **src, t_all *all)
{
	t_light	*result;

	if (!all->scn)
		all->scn = create_screen(NULL, NULL, NULL, 0);
	result = create_light(all->scn->lights);
	if (!result || !all->scn)
		return (1);
	result->name = ft_strdup(src[0]);
	result->point = create_xyz(src[1]);
	result->range = ft_atod(src[2]);
	result->TRGB = create_RGB(src[3]);
	if (result->TRGB == color_trgb(255, 0, 0, 0) || !(result->point))
		return (1);
	if (!all->scn->lights)
		all->scn->lights = result;
	return (0);
}

int	create_C(char **src, t_all *all)
{
	if (!all->scn)
		all->scn = create_screen(NULL, NULL, NULL, 0);
	if (!all->scn)
		return (1);
	if (!all->scn->cam_p)
		all->scn->cam_p = create_xyz(src[1]);
	if (!all->scn->cam_n)
		all->scn->cam_n = create_xyz_norm(src[2]);
	if (!all->scn->fov)
		all->scn->fov = ft_atoi(src[3]);
	if (!all->scn->cam_p || !all->scn->cam_n || all->scn->fov < 0 || \
		all->scn->fov > 180)
		return (1);
	return (0);
}

int	create_sp(char **src, t_all *all)
{
	t_obj	*result;

	result = create_obj(all->objs);
	if (!result)
		return (1);
	result->name = ft_strdup(src[0]);
	result->point = create_xyz(src[1]);
	result->diameter = ft_atod(src[2]);
	result->TRGB = create_RGB(src[3]);
	if (result->TRGB == color_trgb(255, 0, 0, 0) || !(result->point))
		return (1);
	if (!all->objs)
		all->objs = result;
	return (0);
}
