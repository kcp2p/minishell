/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:56:23 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:52 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static t_list_bi	*get_new_splitted_token_node(t_split_info *s_info)
{
	t_list_bi		*new_list;
	t_token_elem	*new_token;

	new_token = create_splitted_word_token_from_src(s_info);
	if (!new_token)
		return (perror_ret_nullptr("malloc"));
	new_list = ft_lstnew_bi((void *)new_token);
	if (!new_list)
	{
		free_token_elem(new_token);
		return (perror_ret_nullptr("malloc"));
	}
	return (new_list);
}

static t_split_info	init_split_info_for_space_splie(\
const char *src, const char *delim, const char *setchars)
{
	t_split_info	split;

	split.src = src;
	split.delim = delim;
	if (!delim)
		split.delim = "";
	split.setchars = setchars;
	if (!setchars)
		split.setchars = "";
	split.is_connect_to_next_word = false;
	split.head_idx = 0;
	split.word_len = 0;
	return (split);
}

t_list_bi	*get_delim_splitted_tokenlist(\
const char *src, const char *delim, const char *setchars)
{
	t_list_bi		*tokenlist_head;
	t_list_bi		*new_list;
	t_split_info	s_info;

	tokenlist_head = NULL;
	if (!src || is_str1chrs_in_str2(delim, setchars))
		return (NULL);
	s_info = init_split_info_for_space_splie(src, delim, setchars);
	while (src[s_info.head_idx])
	{
		new_list = get_new_splitted_token_node(&s_info);
		if (!new_list)
		{
			ft_lstclear_bi(&tokenlist_head, free_token_elem);
			return (perror_ret_nullptr("malloc"));
		}
		ft_lstadd_back_bi(&tokenlist_head, new_list);
	}
	return (tokenlist_head);
}
