/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:28:37 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:28:37 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cpy_len;
	size_t	start_idx;
	char	*ret_str;

	if (s == NULL)
		return (NULL);
	start_idx = (size_t)start;
	if (ft_strlen_nn(s) < start_idx + 1)
		cpy_len = 0;
	else
		cpy_len = min_size(ft_strlen_nn(s) - start_idx, len);
	ret_str = (char *)ft_calloc(sizeof(char), cpy_len + 1);
	if (ret_str == NULL)
		return (NULL);
	ft_memcpy(ret_str, &s[start_idx], cpy_len);
	return (ret_str);
}
