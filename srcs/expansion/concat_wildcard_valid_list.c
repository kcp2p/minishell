/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_wildcard_valid_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:54:14 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static int	*create_realloc_dst(\
t_token_elem **dst, t_token_elem *src, size_t *dst_idx)
{
	size_t	dst_len;
	size_t	src_len;
	int		*flag;

	if (!dst || !*dst || !src)
		return (NULL);
	dst_len = ft_strlen_nn((*dst)->word);
	src_len = ft_strlen_nn(src->word);
	flag = (int *)ft_calloc(sizeof(int), dst_len + src_len + 1);
	if (!flag)
		return (perror_ret_nullptr("malloc"));
	*dst_idx = 0;
	while (*dst_idx < dst_len)
	{
		flag[*dst_idx] = (*dst)->wildcard_valid_flag[*dst_idx];
		*dst_idx += 1;
	}
	return (flag);
}

/* dst=[0,0,0,1], src=[1,1,0] -> concat=[0,0,0,1,1,1,0] */
int	concat_wildcard_valid_list(t_token_elem **dst, t_token_elem *src)
{
	size_t	dst_idx;
	size_t	src_idx;
	int		*flag;

	if (!dst || !*dst || !src)
		return (FAILURE);
	flag = create_realloc_dst(dst, src, &dst_idx);
	if (!flag)
		return (FAILURE);
	free((*dst)->wildcard_valid_flag);
	(*dst)->wildcard_valid_flag = flag;
	if (src->is_quoted)
		return (SUCCESS);
	src_idx = 0;
	while (src->word[src_idx])
	{
		if (src->word[src_idx] == '*')
			flag[dst_idx + src_idx] = 1;
		src_idx++;
	}
	return (SUCCESS);
}
