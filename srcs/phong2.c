/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:32:42 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 13:09:24 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	calc_diff(t_vector *l_rgb, t_vector *norm, t_vector *line_d, \
t_vector *tmp)
{
	double		inner;
	t_vector	d_rgb;

	set_vector(&d_rgb, l_rgb->x, l_rgb->y, l_rgb->z);
	inner = calc_inner_product(norm, line_d);
	if (inner >= 0)
	{
		calc_mply_vec(&d_rgb, inner);
		calc_plus_vec(tmp, &d_rgb);
	}	
	return ;
}

void	calc_mirror(t_vector *l_rgb, t_vector *line_d, \
t_vector *line_v, t_vector *tmp)
{
	t_vector	d_rgb;
	double		inner;
	double		alpha;
	double		km;

	alpha = 9;
	km = 0;
	set_vector(&d_rgb, km * l_rgb->x, km * l_rgb->y, km * l_rgb->z);
	inner = calc_inner_product(line_d, line_v);
	if (inner >= 0)
	{
		calc_mply_vec(&d_rgb, pow(inner, alpha));
		calc_plus_vec(tmp, &d_rgb);
	}
	return ;
}

void	calc_vector_r(t_vector *l, t_vector *norm)
{
	t_vector	tmp;
	t_vector	tmp_n;

	set_vector(&tmp, l->x, l->y, l->z);
	set_vector(&tmp_n, norm->x, norm->y, norm->z);
	calc_mply_vec(&tmp_n, 2 * calc_inner_product(l, norm));
	calc_mply_vec(l, -1);
	calc_plus_vec(l, &tmp_n);
	calc_mply_vec(l, (double)1 / calc_vector_len(l));
	return ;
}

void	color_vector_modify(t_vector *tmp)
{
	if (tmp->x > 255)
		tmp->x = 255;
	if (tmp->y > 255)
		tmp->y = 255;
	if (tmp->z > 255)
		tmp->z = 255;
}

int	color_plus(int	RGB1, int RGB2)
{
	int			result;
	t_vector	tmp1;
	t_vector	tmp2;

	set_vector(&tmp1, (double)trgb_r(RGB1), (double)trgb_g(RGB1), \
	(double)trgb_b(RGB1));
	set_vector(&tmp2, (double)trgb_r(RGB2), (double)trgb_g(RGB2), \
	(double)trgb_b(RGB2));
	calc_plus_vec(&tmp1, &tmp2);
	color_vector_modify(&tmp1);
	result = color_trgb(0, (int)floor(tmp1.x), (int)floor(tmp1.y), \
			(int)floor(tmp1.z));
	return (result);
}
