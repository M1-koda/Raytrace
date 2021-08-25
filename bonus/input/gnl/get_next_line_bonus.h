/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:49:04 by ykohda            #+#    #+#             */
/*   Updated: 2021/07/04 13:07:28 by ykohda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen_g(const char *src);
char		*ft_substr_g(const char *src, unsigned int start, size_t len);
char		*ft_strjoin_g(const char *s1, const char *s2);

#endif
