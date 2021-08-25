/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:51:39 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:12:18 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector_bonus.h"
#include "../includes/screen_bonus.h"

int	color_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b << 0);
}

int	trgb_t(int trgb)
{
	return ((trgb & (0xFF << 24)) >> 24);
}

int	trgb_r(int trgb)
{
	return ((trgb & (0xFF << 16)) >> 16);
}

int	trgb_g(int trgb)
{
	return ((trgb & (0xFF << 8)) >> 8);
}

int	trgb_b(int trgb)
{
	return ((trgb & (0xFF << 0)) >> 0);
}
