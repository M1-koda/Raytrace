/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:55:27 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/03 10:41:16 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include "../includes/screen.h"

static int	detect_tr_cp(t_obj *tr, t_vector *c_p)
{
	t_vector	abc[3];
	t_vector	p3[3];
	t_vector	*cv;
	t_vector	*cv2;
	t_vector	*cv3;
	int		result;

	result = 0;
	//abc
	set_vector(&abc[0], tr->point->x - tr->point2->x, \
	tr->point->y - tr->point2->y, tr->point->z - tr->point2->z);
	set_vector(&abc[1], tr->point2->x - tr->point3->x, \
	tr->point2->y - tr->point3->y, tr->point2->z - tr->point3->z);
	set_vector(&abc[2], tr->point3->x - tr->point->x, \
	tr->point3->y - tr->point->y, tr->point3->z - tr->point->z);
	//p3
	set_vector(&p3[0], tr->point->x - c_p->x, \
	tr->point->y - c_p->y, tr->point->z - c_p->z);
	set_vector(&p3[1], tr->point2->x - c_p->x, \
	tr->point2->y - c_p->y, tr->point2->z - c_p->z);
	set_vector(&p3[2], tr->point3->x - c_p->x, \
	tr->point3->y - c_p->y, tr->point3->z - c_p->z);
	//cv
	cv = calc_cross_product(&p3[0], &abc[0]);
	cv2 = calc_cross_product(&p3[1], &abc[1]);
	cv3 = calc_cross_product(&p3[2], &abc[2]);
	calc_mply_vec(cv, (double)1 / calc_vector_len(cv));
	calc_mply_vec(cv2, (double)1 / calc_vector_len(cv2));
	calc_mply_vec(cv3, (double)1 / calc_vector_len(cv3));
	if (ABS_V(calc_inner_product(cv, cv2) - 1) <= EPS && \
		ABS_V(calc_inner_product(cv2, cv3) - 1) <= EPS)
		result = 1;
	free(cv);
	free(cv2);
	free(cv3);
	return (result);
}

static t_vector	*calc_tr_point_norm(t_obj *tr, t_vector *cam_p, t_vector *d, \
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
	norm = create_new_vector(i * tr->norm->x, i * tr->norm->y, \
		i * tr->norm->z);
	if (!norm || !detect_tr_cp(tr, tmp))
		return (free_return_null(tmp));
	set_vector(point, tmp->x, tmp->y, tmp->z);
	free(tmp);
	tmp = NULL;
	return (norm);
}

t_vector	*calc_tr_line(t_obj *tr, t_vector *cam_p, t_vector *d, \
t_vector **norm)
{
	t_vector	*result;//cross_point
	t_vector	point;

	*norm = free_return_null(*norm);
	result = create_new_vector(tr->point->x - cam_p->x, \
		tr->point->y - cam_p->y, tr->point->z - cam_p->z);
	if (!result)
		return (NULL);
	point.x = calc_inner_product(tr->norm, result);
	point.y = calc_inner_product(tr->norm, d);
	point.z = 0;
	if (point.y <= EPS && point.y >= -1 * EPS)
		return (free_return_null(result));
	if (point.x / point.y >= 0)
		*norm = calc_tr_point_norm(tr, cam_p, d, &point);
	else
		return (free_return_null(result));
	if (!*norm)
		return (free_return_null(result));
	set_vector(result, point.x, point.y, point.z);
	return (result);
}
