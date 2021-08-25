/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:51:39 by ykohda            #+#    #+#             */
/*   Updated: 2021/06/20 19:05:39 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include "../includes/screen.h"

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
