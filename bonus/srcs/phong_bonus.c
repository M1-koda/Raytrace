/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:37:50 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:16:07 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_bonus.h"

static int	calc_diff_mirror(t_vector *k_obj, t_all *all, t_vector *norm, \
t_vector *c_p)
{
	t_vector	q;
	t_light		*l;
	t_vector	line_d;
	t_vector	line_v;

	l = all->scn->lights;
	set_vector(&q, 0, 0, 0);
	while (l && name_checker(l->name, "L"))
		l = l->next;
	while (l)
	{
		if (!name_checker(l->name, "L"))
		{
			set_line_d(&line_d, l, c_p);
			set_line_v(&line_v, all, c_p);
			if (!obj_cross_line(all, &line_d, c_p, l))
			{
				set_plus(&q, diff_set(l, k_obj, norm, &line_d));
				set_plus(&q, mr_set(l, norm, &line_v, &line_d));
			}
		}
		l = l->next;
	}
	color_vector_modify(&q);
	return (color_trgb(0, (int)floor(q.x), (int)floor(q.y), (int)floor(q.z)));
}

static int	calc_ambient(t_vector *k_obj, t_light *amb)
{
	int			result;
	t_vector	l_rgb;

	set_vector(&l_rgb, (double)trgb_r(amb->TRGB), \
		(double)trgb_g(amb->TRGB), (double)trgb_b(amb->TRGB));
	calc_mply_vec(&l_rgb, amb->range);
	l_rgb.x = k_obj->x * l_rgb.x;
	l_rgb.y = k_obj->y * l_rgb.y;
	l_rgb.z = k_obj->z * l_rgb.z;
	result = color_trgb(0, (int)floor(l_rgb.x), (int)floor(l_rgb.y), \
			(int)floor(l_rgb.z));
	return (result);
}

int	calc_phong(int TRGB, t_all *all, t_vector *norm, t_vector *c_p)
{
	int			result;
	t_light		*l_st;
	t_vector	k_obj;

	result = 0;
	l_st = all->scn->lights;
	set_vector(&k_obj, (double)trgb_r(TRGB), (double)trgb_g(TRGB), \
		(double)trgb_b(TRGB));
	calc_mply_vec(&k_obj, (double)1 / 255);
	while (l_st && name_checker(l_st->name, "A"))
		l_st = l_st->next;
	if (l_st)
		result = calc_ambient(&k_obj, l_st);
	l_st = all->scn->lights;
	while (l_st && name_checker(l_st->name, "L"))
		l_st = l_st->next;
	if (l_st)
		result = color_plus(result, \
			calc_diff_mirror(&k_obj, all, norm, c_p));
	return (result);
}
