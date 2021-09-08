/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:59:38 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 06:31:13 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"
#include "input.h"

static double	calc_d(char *src, int flag)
{
	double	result;
	int		i;

	result = 0;
	i = 0;
	while (*(src + i) != '\0' && ft_isdigit(*(src + i)))
	{
		result *= 10;
		result += *(src + i) - '0';
		if (flag == 0 && DBL_MAX / result < 10)
			return (DBL_MAX);
		if (flag == 1 && result / (DBL_MIN * pow(10, \
			calc_digit_number((int)result))) < 10)
			return (DBL_MIN * \
			pow(10, calc_digit_number((int)result)));
		i++;
	}
	return (result);
}

double	ft_atod(char *src)
{
	double	result;
	double	decimal;
	int		i;
	double	sign;

	if (*src == '-')
		i = 1;
	else
		i = 0;
	sign = i;
	decimal = 0;
	result = calc_d(src + i, 0);
	i += calc_digit_number(result);
	if (*(src + i) != '\0' && *(src + i) == '.')
	{
		i += 1;
		decimal = calc_d(src + i, 1);
	}
	result += decimal / pow(10, calc_digit_number((int)decimal));
	if (sign == 1)
		result = -1 * result;
	return (result);
}

int	create_RGB(char *src)
{
	char	**RGB;
	int		R;
	int		G;
	int		B;

	RGB = ft_split(src, ',');
	if (!RGB)
		return (0);
	R = ft_atoi(RGB[0]);
	G = ft_atoi(RGB[1]);
	B = ft_atoi(RGB[2]);
	d_free(RGB);
	if ((0 <= R || R <= 255) && (0 <= G && G <= 255) && \
		(0 <= B || B <= 255))
		return (color_trgb(0, R, G, B));
	else
		return (color_trgb(255, 0, 0, 0));
}

t_vector	*create_xyz(char *src)
{
	char		**xyz;
	double		x;
	double		y;
	double		z;
	t_vector	*result;

	xyz = ft_split(src, ',');
	if (!xyz)
		return (0);
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	d_free(xyz);
	result = create_new_vector(x, y, z);
	if (!result)
		return (NULL);
	return (result);
}

t_vector	*create_xyz_norm(char *src)
{
	t_vector	*res;
	double		len;

	res = create_xyz(src);
	len = sqrt(pow(res->x, 2) + pow(res->y, 2) + pow(res->z, 2));
	calc_mply_vec(res, 1 / len);
	return (res);
}
