/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 09:09:59 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 06:25:18 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"
#include "input.h"

//line kind check
int	scnl_check_create(char **src, t_all *all)
{
	int	result;

	if (!name_checker(src[0], "R") && R_check(src))
	{	
		if (!all->scn)
			all->scn = create_screen(NULL, NULL, NULL, 0);
		if (!all->scn)
			return (1);
		all->scn->w_R = ft_atoi(src[1]);
		all->scn->w_H = ft_atoi(src[2]);
		result = 0;
	}
	else if (!name_checker(src[0], "C") && C_check(src))
		result = create_C(src, all);
	else if (!name_checker(src[0], "A") && A_check(src))
		result = create_A(src, all);
	else if (!name_checker(src[0], "L") && L_check(src))
		result = create_L(src, all);
	else
		result = 1;
	return (result);
}

int	obj_check_create(char **src, t_all *all)
{
	int	result;

	if (!name_checker(src[0], "sp") && sp_check(src))
		result = create_sp(src, all);
	else if (!name_checker(src[0], "pl") && pl_check(src))
		result = create_pl(src, all);
	else if (!name_checker(src[0], "cy") && cy_check(src))
		result = create_cy(src, all);
	else if (!name_checker(src[0], "cn") && cn_check(src))
		result = create_cn(src, all);
	else
		result = 1;
	return (result);
}
