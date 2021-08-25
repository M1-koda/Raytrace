/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cross_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:10:47 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 10:38:04 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/all.h"

int	name_checker(char *query, char *name)
{
	int		result;
	size_t	len;

	result = 0;
	len = ft_strlen((const char *)name);
	if (len != ft_strlen((const char *)query))
		return (1);
	result = ft_strncmp((const char *)query, (const char *)name, len);
	if (result != 0)
		return (1);
	return (0);
}

t_vector	*calc_obj_line(t_obj *obj, t_vector *point, t_vector *d, \
t_vector **norm)
{
	t_vector	*c_p;

	c_p = NULL;
	if (obj == NULL)
	{
		*norm = NULL;
		return (NULL);
	}
	if (!name_checker(obj->name, "sp"))
		c_p = calc_sp_line(obj, point, d, norm);
	else if (!name_checker(obj->name, "pl"))
		c_p = calc_pl_line(obj, point, d, norm);
	else if (!name_checker(obj->name, "cy"))
		c_p = calc_cy_line(obj, point, d, norm);
	else if (!name_checker(obj->name, "cn"))
		c_p = calc_cn_line(obj, point, d, norm);
	return (c_p);
}

t_obj	*detect_obj_line(t_all *all, t_vector *d, t_vector *point, \
t_vector **norm)
{
	t_obj		*tmp;
	t_obj		*result;
	t_vector	*c_p;
	double		min;

	tmp = all->objs;
	result = NULL;
	min = -1;
	while (tmp)
	{
		c_p = calc_obj_line(tmp, point, d, norm);
		if (c_p)
			calc_minus_vec(c_p, point);
		if (c_p && (min < 0 || min > calc_vector_len(c_p)))
		{
			result = tmp;
			min = calc_vector_len(c_p);
		}
		c_p = free_return_null(c_p);
		*norm = free_return_null(*norm);
		tmp = tmp->next;
	}
	return (result);
}

int	obj_cross_line(t_all *all, t_vector *line, t_vector *point, t_light *l)
{
	int			result;
	t_obj		*obj;
	t_vector	*norm;
	t_vector	tmp;
	t_vector	*l_cp;

	result = 0;
	norm = NULL;
	set_vector(&tmp, point->x + 10 * EPS * line->x, \
		point->y + 10 * EPS * line->y, point->z + 10 * EPS * line->z);
	if (detect_obj_line(all, line, &tmp, &norm))
		result = 1;
	obj = detect_obj_line(all, line, &tmp, &norm);
	if (result == 1 && obj)
	{
		l_cp = calc_obj_line(obj, &tmp, line, &norm);
		calc_minus_vec(l_cp, point);
		set_vector(&tmp, l->point->x, l->point->y, l->point->z);
		calc_minus_vec(&tmp, point);
		if (calc_vector_len(l_cp) > calc_vector_len(&tmp))
			result = 0;
		free(l_cp);
	}
	free(norm);
	return (result);
}
