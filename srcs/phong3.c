/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:45:50 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 04:49:15 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

t_vector	*diff_set(t_light *l, t_vector *k_obj, t_vector *norm, \
t_vector *line_d)
{
	t_vector	l_rgb;
	t_vector	q;

	set_vector(&q, 0, 0, 0);
	set_vector(&l_rgb, (double)trgb_r(l->TRGB), \
	(double)trgb_g(l->TRGB), (double)trgb_b(l->TRGB));
	calc_mply_vec(&l_rgb, l->range);
	set_vector(&l_rgb, l_rgb.x * k_obj->x, l_rgb.y * \
	k_obj->y, l_rgb.z * k_obj->z);
	calc_diff(&l_rgb, norm, line_d, &q);
	return (create_new_vector(q.x, q.y, q.z));
}

t_vector	*mr_set(t_light *l, t_vector *norm, t_vector *line_v, \
t_vector *line_d)
{
	t_vector	l_rgb;
	t_vector	q;

	set_vector(&q, 0, 0, 0);
	set_vector(&l_rgb, (double)trgb_r(l->TRGB), \
	(double)trgb_g(l->TRGB), (double)trgb_b(l->TRGB));
	calc_mply_vec(&l_rgb, l->range);
	calc_vector_r(line_d, norm);
	calc_mirror(&l_rgb, line_d, line_v, &q);
	return (create_new_vector(q.x, q.y, q.z));
}

void	set_plus(t_vector *q, t_vector *tmp)
{
	if (tmp)
		calc_plus_vec(q, tmp);
	free(tmp);
}

void	set_line_d(t_vector *line_d, t_light *l, t_vector *c_p)
{
	set_vector(line_d, l->point->x, l->point->y, l->point->z);
	set_normalized_vector_for_light(line_d, c_p);
}

void	set_line_v(t_vector *line_v, t_all *all, t_vector *c_p)
{
	set_vector(line_v, all->scn->cam_p->x, all->scn->cam_p->y, \
	all->scn->cam_p->z);
	set_normalized_vector_for_light(line_v, c_p);
}
