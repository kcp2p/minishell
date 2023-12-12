/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:28:15 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:28:17 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

char	*ft_strdup(const char *s1)
{
	char	*ret_str;
	size_t	len;

	len = ft_strlen(s1);
	ret_str = (char *)ft_calloc(sizeof(char), len + 1);
	if (ret_str == NULL)
		return (NULL);
	ft_memcpy(ret_str, s1, len);
	return (ret_str);
}

char	*ft_strdup_nn(const char *s1)
{
	char	*ret_str;
	size_t	len;

	if (!s1)
	{
		ret_str = (char *)ft_calloc(sizeof(char), 1);
		if (ret_str == NULL)
			return (NULL);
		return (ret_str);
	}
	len = ft_strlen(s1);
	ret_str = (char *)ft_calloc(sizeof(char), len + 1);
	if (ret_str == NULL)
		return (NULL);
	ft_memcpy(ret_str, s1, len);
	return (ret_str);
}
