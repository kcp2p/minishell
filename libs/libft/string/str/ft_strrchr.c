/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:28:33 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:28:33 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret_ptr;
	size_t	i;
	size_t	len;

	ret_ptr = NULL;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			ret_ptr = (char *)&s[i];
		i++;
	}
	return (ret_ptr);
}
