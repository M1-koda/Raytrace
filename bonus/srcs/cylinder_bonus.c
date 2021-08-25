/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:55:27 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:14:28 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector_bonus.h"
#include "../includes/screen_bonus.h"

static t_vector	*calc_norm_part(t_obj *cy, t_vector *cam_p, t_vector *d, \
t_vector *abc)
{
	t_vector	*result;
	t_vector	tmp;
	double		tmp2;

	result = calc_line(cam_p, d, abc->z);
	if (!result)
		return (NULL);
	set_vector(abc, result->x, result->y, result->z);
	calc_minus_vec(result, cy->point);
	tmp2 = calc_inner_product(result, cy->norm);
	if (0 <= tmp2 && tmp2 <= cy->height)
	{
		set_vector(&tmp, cy->norm->x, cy->norm->y, cy->norm->z);
		calc_mply_vec(&tmp, tmp2);
		calc_minus_vec(result, &tmp);
		calc_mply_vec(result, 1 / calc_vector_len(result));
	}
	else
		result = free_return_null(result);
	return (result);
}

static	void	set_calc_t(t_vector *abc, t_vector *tmp)
{
	tmp->x = (-1 * abc->y + sqrt(solution_d(abc->x, abc->y, abc->z))) / \
		(2 * abc->x);
	tmp->y = (-1 * abc->y - sqrt(solution_d(abc->x, abc->y, abc->z))) / \
		(2 * abc->x);
	set_max_min(&(tmp->x), &(tmp->y));
	abc->z = tmp->y;
}

static t_vector	*calc_norm_point(t_obj *cy, t_vector *cam_p, t_vector *d, \
t_vector *abc)
{
	t_vector	*result;
	t_vector	tmp;

	result = NULL;
	if (solution_d(abc->x, abc->y, abc->z) <= EPS)
	{
		abc->z = -1 * abc->y / (2 * abc->x);
		result = calc_norm_part(cy, cam_p, d, abc);
		if (abc->z < 0 || !result)
			return (NULL);
	}
	else
	{
		set_calc_t(abc, &tmp);
		if (tmp.y >= 0)
			result = calc_norm_part(cy, cam_p, d, abc);
		if (!result && tmp.x >= 0)
		{
			abc->z = tmp.x;
			result = calc_norm_part(cy, cam_p, d, abc);
			if (result)
				calc_mply_vec(result, -1);
		}
	}
	return (result);
}

t_vector	*calc_cy_line(t_obj *cy, t_vector *cam_p, t_vector *d, \
t_vector **norm)
{
	t_vector	*result;
	t_vector	*tmp;
	t_vector	abc;

	result = calc_cross_product(d, cy->norm);
	set_vector(&abc, cam_p->x - cy->point->x, cam_p->y - cy->point->y, \
			cam_p->z - cy->point->z);
	tmp = calc_cross_product(&abc, cy->norm);
	if (!tmp || !result)
		return ((t_vector *)free_return_null(result));
	abc.x = pow(calc_vector_len(result), 2);
	abc.y = 2 * calc_inner_product(result, tmp);
	abc.z = pow(calc_vector_len(tmp), 2) - pow(cy->diameter / 2, 2);
	free(tmp);
	free(result);
	if (sqrt(abc.x) <= EPS || solution_d(abc.x, abc.y, abc.z) < 0)
		return (NULL);
	*norm = calc_norm_point(cy, cam_p, d, &abc);
	if (!*norm)
		return ((t_vector *)free_return_null(*norm));
	result = create_new_vector(abc.x, abc.y, abc.z);
	if (!result)
		return ((t_vector *)free_return_null(result));
	return (result);
}
