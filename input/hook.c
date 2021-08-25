/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:51:20 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 06:13:54 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"
#include "input.h"

int	re_draw_image(t_all *all)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_img, 0, 0);
	return (0);
}

int	exit_hook(t_all *t)
{
	free_all(t);
	exit(0);
}

int	key_press(int keycode, t_all *t)
{
	if (keycode == 65307)
		exit_hook(t);
	return (0);
}

void	error_exit(int err)
{
	errno = err;
	if (err != 0)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
