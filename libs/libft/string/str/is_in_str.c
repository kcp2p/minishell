/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:28:45 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:28:46 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

bool	is_chr_in_str(char chr, const char *str)
{
	if (str && ft_strchr(str, chr) != NULL)
		return (true);
	return (false);
}

bool	is_str1chrs_in_str2(const char *str1, const char *str2)
{
	size_t	idx;

	if (!str1 || !str2)
		return (false);
	idx = 0;
	while (str1[idx])
	{
		if (ft_strchr(str2, str1[idx]))
			return (true);
		idx++;
	}
	return (false);
}
