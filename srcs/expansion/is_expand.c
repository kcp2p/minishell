/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:54:35 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

/*
 judge $key in string
  str=$hoo$var$hoge
       ^^^ return true
*/
bool	is_name(const char *str)
{
	size_t	idx;

	if (!str || !str[0])
		return (false);
	if (str[0] != '_' && !ft_isalpha(str[0]))
		return (false);
	idx = 1;
	while (str[idx] && is_chr_in_str(str[idx], STR_EXPAND_EXIT_STATUS))
	{
		if (str[idx] != '_' && !ft_isalnum(str[idx]))
			return (false);
		idx++;
	}
	return (true);
}

// return true if $? or $name in str, do not depend on validate $name
bool	is_expandable_var(const char *str, char quote_chr)
{
	size_t	idx;

	if (!str || quote_chr == CHR_SINGLE_QUOTE)
		return (false);
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == CHR_DOLLAR && str[idx + 1])
		{
			if (str[idx + 1] == CHR_QUESTION)
				return (true);
			if (is_name(&str[idx + 1]))
				return (true);
		}
		idx++;
	}
	return (false);
}

bool	is_str_expandable(const char *str)
{
	if (!str)
		return (false);
	if (str[0] == CHR_DOLLAR && !ft_ispunct(str[1]))
		return (true);
	return (false);
}

bool	is_expandable_exit_status(const char *str)
{
	const size_t	len_flag = ft_strlen_nn(STR_EXPAND_EXIT_STATUS);

	if (ft_strncmp_nn(str, STR_EXPAND_EXIT_STATUS, len_flag) == 0)
		return (true);
	return (false);
}

bool	is_expandable_str_with_dollar(const char *str)
{
	if (!str || str[0] != CHR_DOLLAR)
		return (false);
	if (str[1] == CHR_QUESTION)
		return (true);
	if (str[1] == '_' || ft_isalnum(str[1]))
		return (true);
	return (false);
}
