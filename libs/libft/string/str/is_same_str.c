/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:28:47 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:28:48 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

bool	is_same_str(const char *str1, const char *str2)
{
	const size_t	str1_len = ft_strlen_nn(str1);
	const size_t	str2_len = ft_strlen_nn(str2);

	if (str1_len != str2_len)
		return (false);
	if (ft_strncmp_nn(str1, str2, str1_len) == 0)
		return (true);
	return (false);
}
