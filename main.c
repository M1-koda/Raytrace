/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 07:38:37 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 04:24:26 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/all.h"
#include "./input/input.h"

void	set_all_mlx(t_all *all)
{
	int	display[2];

	all->mlx = mlx_init();
	mlx_get_screen_size(all->mlx, &display[0], &display[1]);
	if (all->scn->w_R > display[0])
		all->scn->w_R = display[0];
	if (all->scn->w_H > display[1])
		all->scn->w_H = display[1];
	set_screen(all->scn, all->scn->w_R, all->scn->w_H, 1);
	all->mlx_win = mlx_new_window(all->mlx, all->scn->w_R, all->scn->w_H, \
	"miniRT");
	all->mlx_img = mlx_new_image(all->mlx, all->scn->w_R, all->scn->w_H);
}

int	detect_obj_output_color(t_all *all, int a, int b)
{
	t_vector	*norm;
	t_vector	*scn_p;
	t_vector	*c_p;
	t_obj		*obj_s;
	int			color;

	norm = NULL;
	scn_p = NULL;
	c_p = NULL;
	obj_s = NULL;
	scn_p = calc_screen_point(all->scn, a, b, 1);
	calc_minus_vec(scn_p, (all->scn)->cam_p);
	calc_mply_vec(scn_p, 1 / calc_vector_len(scn_p));
	obj_s = detect_obj_line(all, scn_p, all->scn->cam_p, &norm);
	c_p = calc_obj_line(obj_s, all->scn->cam_p, scn_p, &norm);
	if (c_p)
		color = calc_phong(obj_s->TRGB, all, norm, c_p);
	else
		color = color_trgb(0, 0, 0, 0);
	norm = free_return_null(norm);
	c_p = free_return_null(c_p);
	scn_p = free_return_null(scn_p);
	return (color);
}

void	mlx_all_hook(t_all *all)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_img, 0, 0);
	mlx_key_hook(all->mlx_win, key_press, all);
	mlx_hook(all->mlx_win, 12, 1L << 15, re_draw_image, all);
	mlx_hook(all->mlx_win, 17, 1L << 17, exit_hook, all);
	mlx_loop(all->mlx);
	mlx_loop_end(all->mlx);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	int		s[3];
	int		color;
	char	*addr;
	int		ab[2];

	all = set_all(argc, argv);
	ab[1] = 0;
	set_all_mlx(all);
	all->img_addr = mlx_get_data_addr(all->mlx_img, &s[0], &s[1], &s[2]);
	while (ab[1] < all->scn->w_H)
	{
		ab[0] = 0;
		while (ab[0] < all->scn->w_R)
		{
			color = detect_obj_output_color(all, ab[0], ab[1]);
			addr = all->img_addr + ab[1] * s[1] + ab[0] * s[0] / 8;
			*(unsigned int *)addr = mlx_get_color_value(all->mlx, \
					color);
			ab[0]++;
		}
		ab[1]++;
	}
	mlx_all_hook(all);
	return (0);
}
