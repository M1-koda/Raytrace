/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:57:46 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 11:58:42 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_bonus.h"
#include "input_bonus.h"

void	d_free_exit(int err, char **src)
{
	d_free(src);
	error_exit(err);
}

int	check_normalized_vec(char *src)
{
	char	**xyz;
	double	x;
	double	y;
	double	z;

	xyz = ft_split(src, ',');
	if (!xyz)
		return (0);
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	d_free(xyz);
	if (ABS_V((sqrt(x * x + y * y + z * z) - 1)) <= EPS)
		return (1);
	return (0);
}

int	ft_isint(char *src)
{
	int	i;

	i = 0;
	if (*src == '-')
		i++;
	while (*(src + i) != '\0')
	{
		if (!ft_isdigit(*(src + i)))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdouble(char *src)
{
	int	i;
	int	decimal_point;

	i = 0;
	if (*src == '-')
		i++;
	decimal_point = 0;
	while (*(src + i) != '\0')
	{
		if (ft_isdigit(*(src + i)))
			;
		else if (decimal_point == 0 && *(src + i) == '.')
			decimal_point = 1;
		else
			return (0);
		i++;
	}
	return (1);
}
