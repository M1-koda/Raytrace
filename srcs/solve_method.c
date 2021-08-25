/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_method.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 03:30:02 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 04:34:10 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

double	MIN(double a, double b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

double	ABS_V(double a)
{
	if (a > 0)
		return (a);
	else
		return (-1 * a);
}

double	solution_d(double a, double b, double c)
{
	double	result;

	result = b * b - 4 * a * c;
	return (result);
}

double	solve_plus_method(double a, double b, double c)
{
	double	result;

	result = -1 * b + pow(solution_d(a, b, c), 0.5);
	result /= 2 * a;
	return (result);
}

double	solve_minus_method(double a, double b, double c)
{
	double	result;

	result = -1 * b - pow(solution_d(a, b, c), 0.5);
	result /= 2 * a;
	return (result);
}
