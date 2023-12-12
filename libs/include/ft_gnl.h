/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:23:09 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:23:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <fcntl.h>

# define BUFFER_SIZE 256

/* gnl */
char		*get_next_line(int fd, bool is_include_nl);
char		*strjoin_and_free_dst(char *dst, char *src);

void		*ft_free_gnl(char **alloc1, char **alloc2);

size_t		ft_strlen_gnl(const char *str);
size_t		count_char(const char c, const char *str);
size_t		ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);

#endif //FT_GNL_H
