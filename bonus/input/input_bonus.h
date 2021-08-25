/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:16:48 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:04:51 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_BONUS_H
# define INPUT_BONUS_H

# include "../includes/all_bonus.h"

int			check_xyz_rgb(char *src, int flag);
int			R_check(char **src);
int			A_check(char **src);
int			L_check(char **src);
int			C_check(char **src);
int			sp_check(char **src);
int			pl_check(char **src);
int			cy_check(char **src);
int			cn_check(char **src);
void		free_error_exit(int err, t_all *all);
int			calc_digit_number(int	digit);
int			calc_dp_len(char **src, int thresh);
void		d_free(char **src);
void		d_free_exit(int err, char **src);
int			check_normalized_vec(char *src);
int			ft_isint(char *src);
int			ft_isdouble(char *src);
int			re_draw_image(t_all *all);
int			exit_hook(t_all *t);
int			key_press(int keycode, t_all *t);
void		error_exit(int err);
int			input_check(char *rt_file, t_all *all, int check);
int			input_file_check(int argc, char **argv);
t_all		*set_all(int argc, char **argv);
int			create_A(char **src, t_all *all);
int			create_L(char **src, t_all *all);
int			create_C(char **src, t_all *all);
int			create_sp(char **src, t_all *all);
int			create_pl(char **src, t_all *all);
int			create_cy(char **src, t_all *all);
int			create_cn(char **src, t_all *all);
int			scnl_check_create(char **src, t_all *all);
int			obj_check_create(char **src, t_all *all);
double		ft_atod(char *src);
int			create_RGB(char *src);
t_vector	*create_xyz(char *src);

#endif
