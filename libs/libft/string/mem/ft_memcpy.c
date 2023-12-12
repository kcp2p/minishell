/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:27:04 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:27:04 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;
	size_t				i;
	size_t				j;

	if (dst == src)
		return (dst);
	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	i = 0;
	j = 0;
	while (i < n)
		dst_cpy[i++] = src_cpy[j++];
	return (dst);
}
