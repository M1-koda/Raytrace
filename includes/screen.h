/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:32:12 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/03 08:35:09 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H
# include "vector.h"

typedef struct s_light
{
	char			*name;
	int				TRGB;
	double			range;
	t_vector		*point;
	struct s_light	*next;
}		t_light;

typedef struct s_screen
{
	t_vector	*cam_p;
	t_vector	*cam_n;
	t_vector	*cam_u;
	t_vector	*cam_v;
	t_light		*lights;
	double		wide;
	double		height;
	double		fov;
	int			w_R;
	int			w_H;
}		t_screen;

t_screen	*create_screen(t_vector *cam_p, t_vector *cam_n, \
			t_light *start, double fov);
void		set_screen(t_screen *scn, double w_R, double w_H, double f);
t_vector	*calc_screen_point(t_screen *scn, double a, double b, double f);

#endif
