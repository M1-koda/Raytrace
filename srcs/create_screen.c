/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:32:08 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 05:13:29 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/screen.h"

t_screen	*create_screen(t_vector *cam_p, t_vector *cam_n, \
t_light *start, double fov)
{
	t_screen	*result;

	result = malloc(sizeof(t_screen) * 1);
	if (!result)
		return (NULL);
	result->cam_p = NULL;
	result->cam_n = NULL;
	if (cam_p)
		result->cam_p = create_new_vector(cam_p->x, cam_p->y, cam_p->z);
	if (cam_n)
		result->cam_n = create_new_vector(cam_n->x, cam_n->y, cam_n->z);
	result->fov = fov;
	result->w_R = 1080;
	result->w_H = 1080;
	result->wide = 0;
	result->height = 0;
	result->cam_u = NULL;
	result->cam_v = NULL;
	result->lights = start;
	return (result);
}

void	set_screen(t_screen *scn, double w_R, double w_H, double f)
{
	double	aspect;

	if (!scn)
		return ;
	aspect = w_H / w_R;
	scn->w_R = w_R;
	scn->w_H = w_H;
	scn->wide = 2 * f * tan((scn->fov / 180 * M_PI) / 2);
	scn->height = aspect * scn->wide;
	set_world(scn->cam_n, &(scn->cam_u), &(scn->cam_v));
	return ;
}

t_vector	*calc_screen_point(t_screen *scn, double a, double b, double f)
{
	t_vector	*result;
	double		x;
	double		y;
	double		z;

	x = scn->cam_p->x + scn->cam_n->x * f + \
	    scn->cam_u->x * scn->wide * (2 * a - scn->w_R) / (2 * scn->w_R) - \
	    scn->cam_v->x * scn->height * (2 * b - scn->w_H) / (2 * scn->w_H);
	y = scn->cam_p->y + scn->cam_n->y * f + \
	    scn->cam_u->y * scn->wide * (2 * a - scn->w_R) / (2 * scn->w_R) - \
	    scn->cam_v->y * scn->height * (2 * b - scn->w_H) / (2 * scn->w_H);
	z = scn->cam_p->z + scn->cam_n->z * f + \
	    scn->cam_u->z * scn->wide * (2 * a - scn->w_R) / (2 * scn->w_R) - \
	    scn->cam_v->z * scn->height * (2 * b - scn->w_H) / (2 * scn->w_H);
	result = create_new_vector(x, y, z);
	return (result);
}
