/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:20:10 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 06:02:34 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

void	set_normalized_vector_for_light(t_vector *set, t_vector *o)
{
	calc_minus_vec(set, o);
	calc_mply_vec(set, 1 / calc_vector_len(set));
	return ;
}

void	calc_mply_vec(t_vector *d, double t)
{
	if (d == NULL)
		return ;
	d->x = d->x * t;
	d->y = d->y * t;
	d->z = d->z * t;
	return ;
}

void	calc_plus_vec(t_vector *a, t_vector *b)
{
	if (!a || !b)
		return ;
	a->x = a->x + b->x;
	a->y = a->y + b->y;
	a->z = a->z + b->z;
	return ;
}

void	calc_minus_vec(t_vector *a, t_vector *b)
{
	if (!a || !b)
		return ;
	a->x = a->x - b->x;
	a->y = a->y - b->y;
	a->z = a->z - b->z;
	return ;
}

double	calc_vector_len(t_vector *vec)
{
	double	result;

	result = pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2);
	result = sqrt(result);
	return (result);
}
