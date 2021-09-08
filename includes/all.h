/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 05:29:28 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 10:46:26 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "vector.h"
# include "screen.h"
# include "../libft/libft.h"
# include <X11/Xlib.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include "../minilibx-linux/mlx.h"
# include "../input/gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <float.h>
# include <fcntl.h>

typedef struct s_all
{
	t_screen	*scn;
	t_obj		*objs;
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	void		*img_addr;
}		t_all;

t_all		*create_all(t_screen *scn, t_obj *objs);
t_obj		*detect_obj_line(t_all *all, t_vector *d, t_vector *point, \
			t_vector **norm);
t_obj		*create_obj(t_obj *start);
t_light		*create_light(t_light *start);
int			calc_phong(int TRGB, t_all *all, t_vector *norm, t_vector *c_p);
int			obj_cross_line(t_all *all, t_vector *line, t_vector *point, \
			t_light *l);
void		free_lights(t_light *start);
void		free_scn(t_screen *scn);
void		free_objs(t_obj *start);
void		free_all(t_all *all);
void		calc_vector_r(t_vector *l, t_vector *norm);
void		calc_mirror(t_vector *l_rgb, t_vector *line_d, \
		t_vector *line_v, t_vector *tmp);
void		calc_diff(t_vector *l_rgb, t_vector *norm, t_vector *line_d, \
		t_vector *tmp);
t_vector	*diff_set(t_light *l, t_vector *k_obj, t_vector *norm, \
		t_vector *line_d);
t_vector	*mr_set(t_light *l, t_vector *norm, t_vector *line_v, \
		t_vector *line_d);
void		set_plus(t_vector *q, t_vector *tmp);
void		set_line_d(t_vector *line_d, t_light *l, t_vector *c_p);
void		set_line_v(t_vector *line_v, t_all *all, t_vector *c_p);

#endif
