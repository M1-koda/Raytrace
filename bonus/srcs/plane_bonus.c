/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:53:27 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:16:26 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector_bonus.h"
#include "../includes/screen_bonus.h"

static t_vector	*calc_pl_point_norm(t_obj *pl, t_vector *cam_p, t_vector *d, \
t_vector *point)
{
	t_vector	*norm;
	t_vector	*tmp;
	double		i;

	i = 1;
	norm = NULL;
	tmp = calc_line(cam_p, d, point->x / point->y);
	if (!tmp)
		return (NULL);
	if (point->y > 0)
		i = -1;
	else
		i = 1;
	norm = create_new_vector(i * pl->norm->x, i * pl->norm->y, \
		i * pl->norm->z);
	if (!norm)
		return (free_return_null(tmp));
	set_vector(point, tmp->x, tmp->y, tmp->z);
	free(tmp);
	tmp = NULL;
	return (norm);
}

t_vector	*calc_pl_line(t_obj *pl, t_vector *cam_p, t_vector *d, \
t_vector **norm)
{
	t_vector	*result;
	t_vector	point;

	*norm = free_return_null(*norm);
	result = create_new_vector(pl->point->x - cam_p->x, \
		pl->point->y - cam_p->y, pl->point->z - cam_p->z);
	if (!result)
		return (NULL);
	point.x = calc_inner_product(pl->norm, result);
	point.y = calc_inner_product(pl->norm, d);
	point.z = 0;
	if (point.y <= EPS && point.y >= -1 * EPS)
		return (free_return_null(result));
	if (point.x / point.y >= 0)
		*norm = calc_pl_point_norm(pl, cam_p, d, &point);
	else
		return (free_return_null(result));
	if (!*norm)
		return (free_return_null(result));
	set_vector(result, point.x, point.y, point.z);
	return (result);
}
