/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:25:15 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:25:18 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_std.h"

static int	get_num_digits(long long num)
{
	int	num_digits;

	num_digits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num_digits += 1;
		num /= 10;
	}
	return (num_digits);
}

static void	set_params(int n, long long *num, size_t *len, size_t *num_head_idx)
{
	*num = (long long)n;
	*len = 0;
	*num_head_idx = 0;
	if (*num < 0)
	{
		*len += 1;
		*num *= (-1);
		*num_head_idx = 1;
	}
	*len += get_num_digits(*num);
}

char	*ft_itoa(int n)
{
	long long	num;
	size_t		itoa_len;
	size_t		num_head_idx;
	char		*ret_str;

	set_params(n, &num, &itoa_len, &num_head_idx);
	ret_str = (char *)ft_calloc(sizeof(char), itoa_len + 1);
	if (ret_str == NULL)
		return (NULL);
	while (itoa_len > num_head_idx)
	{
		ret_str[itoa_len - 1] = (char)(num % 10 + '0');
		num /= 10;
		itoa_len--;
	}
	if (num_head_idx == 1)
		ret_str[0] = '-';
	return (ret_str);
}
