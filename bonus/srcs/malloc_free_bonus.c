/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 05:28:45 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:15:08 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_bonus.h"

void	*free_return_null(void *tmp)
{
	free(tmp);
	return (NULL);
}

void	set_max_min(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	if (*a < *b)
	{
		*a = *b;
		*b = tmp;
	}
	return ;
}

void	free_lights(t_light *start)
{
	t_light	*tmp;

	while (start)
	{
		tmp = start->next;
		free(start->name);
		free(start->point);
		free(start);
		start = tmp;
	}
}

void	free_scn(t_screen *scn)
{
	if (scn)
	{
		free(scn->cam_p);
		free(scn->cam_n);
		free(scn->cam_u);
		free(scn->cam_v);
		free_lights(scn->lights);
		free(scn);
	}
}

void	free_objs(t_obj *start)
{
	t_obj	*tmp;

	while (start)
	{
		tmp = start->next;
		free(start->name);
		free(start->norm);
		free(start->point);
		free(start);
		start = tmp;
	}
}
