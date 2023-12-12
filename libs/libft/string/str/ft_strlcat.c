/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:28:22 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:28:22 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cat_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	cat_len = min_size(dstsize - dst_len - 1, src_len);
	ft_memcpy(&dst[dst_len], &src[0], cat_len);
	dst[dst_len + cat_len] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlcat_nn(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cat_len;

	src_len = ft_strlen_nn(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen_nn(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	cat_len = min_size(dstsize - dst_len - 1, src_len);
	ft_memcpy(&dst[dst_len], &src[0], cat_len);
	dst[dst_len + cat_len] = '\0';
	return (dst_len + src_len);
}
