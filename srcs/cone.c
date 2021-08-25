/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:54:48 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 10:36:43 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include "../includes/screen.h"

static t_vector	*calc_condition(t_obj *cn, double cos, t_vector *result)
{
	t_vector	tmp1;
	double		tmp;

	calc_minus_vec(result, cn->point);
	if (0 <= calc_inner_product(result, cn->norm) && \
		calc_inner_product(result, cn->norm) <= cn->height)
	{
		tmp = calc_vector_len(result) / cos;
		set_vector(&tmp1, tmp * cn->norm->x, tmp * cn->norm->y, \
				tmp * cn->norm->z);
		calc_minus_vec(result, &tmp1);
		calc_mply_vec(result, 1 / calc_vector_len(result));
	}
	else
		return ((t_vector *)free_return_null(result));
	return (result);
}

static t_vector	*calc_condition2(t_obj *cn, t_vector *d, t_vector *t, \
t_vector *abc)
{
	t_vector	*result;
	t_vector	cam_p;	

	result = NULL;
	set_vector(&cam_p, abc->x, abc->y, abc->z);
	if (t->z >= 0)
	{
		result = calc_line(&cam_p, d, t->z);
		if (!result)
			return (NULL);
		set_vector(abc, result->x, result->y, result->z);
		result = calc_condition(cn, t->x, result);
	}
	if (!result && t->y >= 0)
	{
		result = calc_line(&cam_p, d, t->y);
		if (!result)
			return (NULL);
		set_vector(abc, result->x, result->y, result->z);
		result = calc_condition(cn, t->x, result);
		if (result)
			calc_mply_vec(result, -1);
	}
	return (result);
}

static t_vector	*calc_norm_pt(t_obj *cn, t_vector *cam_p, t_vector *d, \
t_vector *abc)
{
	t_vector	*result;
	t_vector	tmp;

	tmp.x = cn->height / sqrt(pow(cn->height, 2) + pow(cn->diameter / 2, 2));
	if (ABS_V(abc->y) <= EPS || tmp.x <= EPS)
		return (NULL);
	else
		tmp.y = -1 * abc->z / abc->y;
	result = calc_line(cam_p, d, tmp.y);
	if (tmp.y < 0 || !result)
		return ((t_vector *)free_return_null(result));
	set_vector(abc, result->x, result->y, result->z);
	result = calc_condition(cn, tmp.x, result);
	if (result && calc_inner_product(d, cn->norm) < 0)
		calc_mply_vec(result, -1);
	return (result);
}

static t_vector	*calc_norm_pt2(t_obj *cn, t_vector *cam_p, t_vector *d, \
t_vector *abc)
{
	t_vector	*result;
	t_vector	tmp;
	double		D;

	result = NULL;
	tmp.x = cn->height / sqrt(pow(cn->height, 2) + pow(cn->diameter / 2, 2));
	D = solution_d(abc->x, abc->y, abc->z);
	if (D <= EPS)
	{
		tmp.y = -1 * abc->y / (2 * abc->x);
		result = calc_line(cam_p, d, tmp.y);
		if (tmp.y < 0 || !result)
			return ((t_vector *)free_return_null(result));
		set_vector(abc, result->x, result->y, result->z);
		result = calc_condition(cn, tmp.x, result);
	}
	else
	{
		tmp.y = (-1 * abc->y + sqrt(D)) / (2 * abc->x);
		tmp.z = (-1 * abc->y - sqrt(D)) / (2 * abc->x);
		set_max_min(&(tmp.y), &(tmp.z));
		set_vector(abc, cam_p->x, cam_p->y, cam_p->z);
		result = calc_condition2(cn, d, &tmp, abc);
	}
	return (result);
}

t_vector	*calc_cn_line(t_obj *cn, t_vector *cam_p, t_vector *d, \
t_vector **norm)
{
	t_vector	*result;
	t_vector	tmp;
	t_vector	tmp1;
	t_vector	abc;

	result = NULL;
	*norm = NULL;
	tmp1.x = cn->height / sqrt(pow(cn->height, 2) + pow(cn->diameter / 2, 2));
	set_vector(&tmp, cam_p->x - cn->point->x, cam_p->y - cn->point->y, \
			cam_p->z - cn->point->z);
	tmp1.y = calc_inner_product(d, cn->norm);
	tmp1.z = calc_inner_product(&tmp, cn->norm);
	abc.x = pow(tmp1.y, 2) - pow(calc_vector_len(d) * tmp1.x, 2);
	abc.y = 2 * (tmp1.y * tmp1.z - calc_inner_product(d, &tmp) * \
		pow(tmp1.x, 2));
	abc.z = pow(tmp1.z, 2) - pow(calc_vector_len(&tmp) * tmp1.x, 2);
	if (ABS_V(abc.x) <= EPS)
		*norm = calc_norm_pt(cn, cam_p, d, &abc);
	else if (solution_d(abc.x, abc.y, abc.z) > 0)
		*norm = calc_norm_pt2(cn, cam_p, d, &abc);
	if (*norm)
		result = create_new_vector(abc.x, abc.y, abc.z);
	if (!result)
		return (free_return_null(*norm));
	return (result);
}
