/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:51:25 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 05:16:37 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	free_all(t_all *all)
{
	free_scn(all->scn);
	free_objs(all->objs);
	if (all->mlx)
	{
		mlx_destroy_image(all->mlx, all->mlx_img);
		mlx_destroy_window(all->mlx, all->mlx_win);
		mlx_destroy_display(all->mlx);
		free(all->mlx);
	}
	free(all);
}

t_light	*create_light(t_light *start)
{
	t_light	*result;

	result = malloc(sizeof(t_light) * 1);
	if (!result)
		return (NULL);
	result->name = NULL;
	result->point = NULL;
	result->TRGB = 0;
	result->range = 0;
	result->next = NULL;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = result;
	}
	return (result);
}

t_obj	*create_obj(t_obj *start)
{
	t_obj	*result;

	result = malloc(sizeof(t_obj) * 1);
	if (!result)
		return (NULL);
	result->name = NULL;
	result->norm = NULL;
	result->point = NULL;
	result->height = 0;
	result->diameter = 0;
	result->TRGB = 0;
	result->next = NULL;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = result;
	}
	return (result);
}

t_all	*create_all(t_screen *scn, t_obj *objs)
{
	t_all	*all;

	all = malloc(sizeof(t_all) * 1);
	if (!all)
		return (NULL);
	all->scn = scn;
	all->objs = objs;
	all->mlx = NULL;
	all->mlx_win = NULL;
	all->mlx_img = NULL;
	all->img_addr = NULL;
	return (all);
}
