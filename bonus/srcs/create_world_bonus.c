/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:04:26 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:14:08 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector_bonus.h"

void	set_world(t_vector *n, t_vector **u, t_vector **v)
{
	t_vector	*v_up;

	v_up = create_new_vector(0, 0, 1);
	*u = calc_cross_product(n, v_up);
	if (!*u)
		return ;
	else if (calc_vector_len(*u) < EPS)
	{
		if (n->z > 0)
			set_vector(*u, 0, 1, 0);
		else
			set_vector(*u, -1, 0, 0);
	}
	else
		calc_mply_vec(*u, 1 / calc_vector_len(*u));
	*v = calc_cross_product(*u, n);
	if (!*v)
		return ;
	else
		calc_mply_vec(*v, 1 / calc_vector_len(*v));
	free(v_up);
	return ;
}
