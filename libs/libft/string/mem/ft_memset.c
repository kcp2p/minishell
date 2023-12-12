/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:27:09 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:27:10 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*str;
	const unsigned char	chr = (const unsigned char)c;
	size_t				i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		str[i++] = chr;
	return (s);
}

void	*ft_memset_nn(void *s, int c, size_t n)
{
	unsigned char		*str;
	const unsigned char	chr = (const unsigned char)c;
	size_t				i;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		str[i++] = chr;
	return (s);
}
