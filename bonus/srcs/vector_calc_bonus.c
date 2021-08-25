/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:45:04 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:17:36 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector_bonus.h"

t_vector	*create_new_vector(double x, double y, double z)
{
	t_vector	*result;

	result = malloc(sizeof(t_vector) * 1);
	if (!result)
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

void	set_vector(t_vector *set, double x, double y, double z)
{
	if (!set)
		return ;
	set->x = x;
	set->y = y;
	set->z = z;
	return ;
}

double	calc_inner_product(t_vector *a, t_vector *b)
{
	double	result;

	result = a->x * b->x + a->y * b->y + a->z * b->z;
	return (result);
}

t_vector	*calc_cross_product(t_vector *a, t_vector *b)
{
	t_vector	*result;

	if (a == NULL || b == NULL)
		return (NULL);
	result = create_new_vector(\
		a->y * b->z - a->z * b->y, \
		a->z * b->x - a->x * b->z, \
		a->x * b->y - a->y * b->x);
	if (!result)
		return (NULL);
	return (result);
}

t_vector	*calc_line(t_vector *point, t_vector *vec, double t)
{
	t_vector	*result;

	result = create_new_vector(vec->x, vec->y, vec->z);
	if (!result)
		return (NULL);
	calc_mply_vec(result, t);
	calc_plus_vec(result, point);
	return (result);
}
