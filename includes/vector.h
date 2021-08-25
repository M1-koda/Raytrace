/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:36:53 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/03 07:39:45 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef EPS
#  define EPS 1e-10
# endif

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;

}		t_vector;

typedef struct s_obj
{
	char			*name;
	t_vector		*norm;
	t_vector		*point;
	double			height;
	double			diameter;
	int				TRGB;
	struct s_obj	*next;
}		t_obj;

double		MIN(double a, double b);
double		ABS_V(double a);
void		calc_mply_vec(t_vector *d, double t);
void		calc_plus_vec(t_vector *a, t_vector *b);
t_vector	*create_new_vector(double x, double y, double z);
double		calc_inner_product(t_vector *a, t_vector *b);
t_vector	*calc_cross_product(t_vector *a, t_vector *b);
t_vector	*calc_line(t_vector *point, t_vector *vector, double t);
int			color_trgb(int t, int r, int g, int b);
int			trgb_t(int trgb);
int			trgb_r(int trgb);
int			trgb_g(int trgb);
int			trgb_b(int trgb);
t_vector	*calc_cn_line(t_obj *cn, t_vector *cam_p, t_vector *d, \
		t_vector **norm);
void		set_world(t_vector *n, t_vector **u, t_vector **v);
t_vector	*calc_cy_line(t_obj *cy, t_vector *cam_p, t_vector *d, \
		t_vector **norm);
void		*free_return_null(void *tmp);
int			name_checker(char *query, char *name);
t_vector	*calc_obj_line(t_obj *obj, t_vector *point, t_vector *d, \
		t_vector **norm);
void		color_vector_modify(t_vector *tmp);
int			color_plus(int	RGB1, int RGB2);
t_vector	*calc_pl_line(t_obj *pl, t_vector *cam_p, t_vector *d, \
		t_vector **norm);
double		solution_d(double a, double b, double c);
double		solve_plus_method(double a, double b, double c);
double		solve_minus_method(double a, double b, double c);
t_vector	*calc_sp_line(t_obj *sp, t_vector *cam_p, t_vector *d, \
		t_vector **norm);
t_vector	*create_new_vector(double x, double y, double z);
void		set_vector(t_vector *set, double x, double y, double z);
double		calc_inner_product(t_vector *a, t_vector *b);
t_vector	*calc_cross_product(t_vector *a, t_vector *b);
t_vector	*calc_line(t_vector *point, t_vector *vec, double t);
void		set_normalized_vector_for_light(t_vector *set, t_vector *o);
void		calc_mply_vec(t_vector *d, double t);
void		calc_plus_vec(t_vector *a, t_vector *b);
void		calc_minus_vec(t_vector *a, t_vector *b);
double		calc_vector_len(t_vector *vec);
void		set_max_min(double *a, double *b);

#endif
