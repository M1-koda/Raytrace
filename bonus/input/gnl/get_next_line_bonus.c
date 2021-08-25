/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:47:44 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 12:07:35 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../../includes/all_bonus.h"

static int	ft_init(char **line, char *buf, size_t *i, ssize_t *bufsize)
{
	*line = malloc(sizeof(char) * 1);
	if (*line == NULL)
		return (0);
	**line = '\0';
	if (*buf == '\0')
		*bufsize = 0;
	else
		*bufsize = 1;
	*i = 0;
	return (1);
}

static int	ft_final(char **line, ssize_t bufsize)
{
	if (!*line)
		return (-1);
	else if (bufsize <= 0)
		return (0);
	else
		return (1);
}

static int	ft_newline(char **line, char *buf, size_t *start, int fd)
{
	size_t	i;
	ssize_t	bufsize;

	if (!ft_init(line, buf, &i, &bufsize))
		return (-1);
	while (*(buf + *start + i) != '\n' && bufsize > 0)
	{
		if (*(buf + *start + i) == '\0')
		{
			*line = ft_strjoin_g(*line, ft_substr_g(buf, *start, i));
			bufsize = read(fd, buf, BUFFER_SIZE);
			if (!*line || bufsize < 0)
				return (-1);
			i = -1;
			*start = 0;
			buf[bufsize] = '\0';
		}
		i += 1;
	}
	if (bufsize > 0 && *(buf + *start + i) == '\n')
	{
		*line = ft_strjoin_g(*line, ft_substr_g(buf, *start, i));
		*start += ++i;
	}
	return (ft_final(line, bufsize));
}

static char	*reset_value(size_t *start, char *buf)
{
	*start = 0;
	return (free_return_null(buf));
}

int	get_next_line(int fd, char **line)
{
	static char		*buf;
	static size_t	start;
	ssize_t			bufsize;
	int				result;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE == SIZE_MAX \
		|| !line || read(fd, 0, 0) < 0)
		return (-1);
	if (buf == NULL)
	{
		buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		bufsize = read(fd, buf, BUFFER_SIZE);
		if (!buf || bufsize < 0)
		{
			buf = free_return_null(buf);
			return (-1);
		}
		*(buf + bufsize) = '\0';
	}
	result = ft_newline(line, buf, &start, fd);
	if (result <= 0)
		buf = reset_value(&start, buf);
	return (result);
}
