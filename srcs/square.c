/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:54:28 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 05:54:53 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include "../includes/screen.h"

static int	detect_sq_cp(t_obj *sq, t_vector *c_p, t_vector *norm)
{
	t_vector	*u;
	t_vector	*v;
	t_vector	cp;
	int		result;

	result = 0;
	set_world(norm, &u, &v);
	set_vector(&cp, c_p->x - sq->point->x, c_p->y - sq->point->y, \
	c_p->z - sq->point->z);
	if (ABS_V(calc_inner_product(&cp, u)) <= sq->diameter / 2 && \
		ABS_V(calc_inner_product(&cp, v)) <= sq->diameter / 2)
		result = 1;
	free(v);
	free(u);
	return (result);
}

static t_vector	*calc_sq_point_norm(t_obj *sq, t_vector *cam_p, t_vector *d, \
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
	norm = create_new_vector(i * sq->norm->x, i * sq->norm->y, \
		i * sq->norm->z);
	if (!norm || !detect_sq_cp(sq, tmp, norm))
		return (free_return_null(tmp));
	set_vector(point, tmp->x, tmp->y, tmp->z);
	free(tmp);
	tmp = NULL;
	return (norm);
}

t_vector	*calc_sq_line(t_obj *sq, t_vector *cam_p, t_vector *d, \
t_vector **norm)
{
	t_vector	*result;
	t_vector	point;

	*norm = free_return_null(*norm);
	result = create_new_vector(sq->point->x - cam_p->x, \
		sq->point->y - cam_p->y, sq->point->z - cam_p->z);
	if (!result)
		return (NULL);
	point.x = calc_inner_product(sq->norm, result);
	point.y = calc_inner_product(sq->norm, d);
	point.z = 0;
	if (point.y <= EPS && point.y >= -1 * EPS)
		return (free_return_null(result));
	if (point.x / point.y >= 0)
		*norm = calc_sq_point_norm(sq, cam_p, d, &point);
	else
		return (free_return_null(result));
	if (!*norm)
		return (free_return_null(result));
	set_vector(result, point.x, point.y, point.z);
	return (result);
}
