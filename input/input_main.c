/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 09:15:58 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 13:18:09 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"
#include "input.h"

int	first_time_RCAL(char c)
{
	static int	RCAL[4];
	int			index;

	index = 4;
	if (c == 'R' && !RCAL[0])
		index = 0;
	else if (c == 'C' && !RCAL[1])
		index = 1;
	else if (c == 'A' && !RCAL[2])
		index = 2;
	else if (c == 'L' && !RCAL[3])
		index = 3;
	if (index < 4)
	{
		RCAL[index] = 1;
		return (1);
	}
	return (0);
}

int	input_check(char *rt_file, t_all *all, int check)
{
	char	**data;

	if (!check && !(*rt_file == '#' || *rt_file == '\0'))
	{
		data = ft_split(rt_file, ' ');
		if (data[0] && ft_strchr("RCAL", data[0][0]) && \
			first_time_RCAL(data[0][0]))
			check = scnl_check_create(data, all);
		else if (data[0] && ft_strchr("spc", data[0][0]))
			check = obj_check_create(data, all);
		else if (data[0] && ft_isalnum(data[0][0]))
			check = 1;
		d_free(data);
		free(rt_file);
		data = NULL;
	}
	else
		free(rt_file);
	return (check);
}

int	input_file_check(int argc, char **argv)
{
	int		fd;
	char	*rt_file;

	if (argc != 2)
		error_exit(ESRCH);
	rt_file = ft_strchr(argv[argc - 1] + 1, '.');
	if (!rt_file || *(rt_file + 1) == '\0')
		error_exit(EINVAL);
	rt_file = rt_file + 1;
	if (ft_strncmp(rt_file, "rt", ft_strlen(rt_file)))
		error_exit(EINVAL);
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd < 0)
		error_exit(EBADF);
	return (fd);
}

t_all	*set_all(int argc, char **argv)
{
	int		fd;
	int		check;
	char	*rt_file;
	t_all	*all;

	check = 0;
	fd = input_file_check(argc, argv);
	all = create_all(NULL, NULL);
	if (!all)
		error_exit(ENOMEM);
	while (get_next_line(fd, &rt_file) > 0)
	{	
		check = input_check(rt_file, all, check);
		rt_file = NULL;
	}
	check = input_check(rt_file, all, check);
	rt_file = NULL;
	close(fd);
	if (check || !all->scn->cam_p)
		free_error_exit(EINVAL, all);
	return (all);
}
