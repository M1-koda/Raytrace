/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:54:28 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 05:54:53 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

static void	set_sp_norm(t_obj *sp, t_vector *result, t_vector *abc, \
double minus)
{
	set_vector(abc, result->x, result->y, result->z);
	calc_minus_vec(result, sp->point);
	calc_mply_vec(result, minus * 1 / calc_vector_len(result));
}

static t_vector	*calc_norm_point_1(t_vector *abc, t_obj *sp, t_vector *cam_p, \
t_vector *d)
{
	t_vector	*result;
	double		t_1;
	double		t_2;

	result = NULL;
	t_1 = (-1 * abc->y + sqrt(abc->z)) / (2 * abc->x);
	t_2 = (-1 * abc->y - sqrt(abc->z)) / (2 * abc->x);
	if (t_1 >= 0 && t_2 >= 0)
	{
		result = calc_line(cam_p, d, MIN(t_1, t_2));
		if (!result)
			return (NULL);
		set_sp_norm(sp, result, abc, 1);
	}
	else if (t_1 >= 0 || t_2 >= 0)
	{
		if (t_2 > t_1)
			result = calc_line(cam_p, d, t_2);
		else
			result = calc_line(cam_p, d, t_1);
		if (!result)
			return (NULL);
		set_sp_norm(sp, result, abc, -1);
	}
	return (result);
}

static t_vector	*calc_norm_point(t_vector *abc, t_obj *sp, t_vector *cam_p, \
t_vector *d)
{
	t_vector	*result;

	result = NULL;
	if (abc->z >= EPS)
		result = calc_norm_point_1(abc, sp, cam_p, d);
	else if (abc->z >= 0 && -1 * abc->y / (2 * abc->x) >= 0)
	{
		result = calc_line(cam_p, d, -1 * abc->y / (2 * abc->x));
		if (!result)
			return (NULL);
		set_vector(abc, result->x, result->y, result->z);
		calc_minus_vec(result, sp->point);
		calc_mply_vec(result, 1 / calc_vector_len(result));
	}
	return (result);
}

t_vector	*calc_sp_line(t_obj *sp, t_vector *cam_p, t_vector *d, \
t_vector **norm)
{
	t_vector	*result;
	t_vector	abc;
	double		D;

	abc.x = pow(calc_vector_len(d), 2);
	result = create_new_vector(cam_p->x - sp->point->x, \
		cam_p->y - sp->point->y, cam_p->z - sp->point->z);
	if (!result)
		return (NULL);
	abc.y = 2 * calc_inner_product(result, d);
	abc.z = pow(calc_vector_len(result), 2) - pow(sp->diameter / 2, 2);
	free(result);
	result = NULL;
	D = solution_d(abc.x, abc.y, abc.z);
	abc.z = D;
	if (D >= 0)
	{
		*norm = calc_norm_point(&abc, sp, cam_p, d);
		if (*norm != NULL)
			result = create_new_vector(abc.x, abc.y, abc.z);
		if (*norm != NULL && !result)
			*norm = free_return_null(*norm);
	}
	return (result);
}
