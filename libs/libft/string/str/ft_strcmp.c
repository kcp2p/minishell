/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:28:14 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:28:14 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

int	ft_strcmp_nn(const char *s1, const char *s2)
{
	const unsigned char	*str1 = (const unsigned char *)s1;
	const unsigned char	*str2 = (const unsigned char *)s2;
	size_t				idx;

	if (!s1 || !s2)
		return (0);
	idx = 0;
	while (str1[idx] && str2[idx])
	{
		if (str1[idx] != str2[idx])
			break ;
		idx++;
	}
	return ((int)(str1[idx] - str2[idx]));
}
