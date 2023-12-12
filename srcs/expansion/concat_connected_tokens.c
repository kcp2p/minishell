/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_connected_tokens.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:54:00 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

bool	check_valid_wildcard_in_word(t_token_elem *token)
{
	size_t	idx;

	if (!token)
		return (false);
	idx = 0;
	while (token->word[idx])
	{
		if (token->wildcard_valid_flag[idx] == 1)
			return (true);
		idx++;
	}
	return (false);
}

static int	get_wildcard_valid_lsit(t_token_elem **token)
{
	size_t	len;
	size_t	idx;

	if (!token || !*token || !(*token)->word)
		return (FAILURE);
	len = ft_strlen_nn((*token)->word);
	(*token)->wildcard_valid_flag = (int *)ft_calloc(sizeof(int), len + 1);
	if (!(*token)->wildcard_valid_flag)
		return (perror_ret_int("malloc", FAILURE));
	if ((*token)->is_quoted)
		return (SUCCESS);
	idx = 0;
	while ((*token)->word[idx])
	{
		if ((*token)->word[idx] == '*')
			(*token)->wildcard_valid_flag[idx] = 1;
		idx++;
	}
	return (SUCCESS);
}

static int	concat_connected_words(t_list_bi **node, t_token_elem **token)
{
	t_list_bi		*popped_node;
	t_token_elem	*append;

	while (*node)
	{
		popped_node = ft_lstpop_bi(node);
		append = popped_node->content;
		if (concat_wildcard_valid_list(token, append) == FAILURE)
		{
			ft_lstclear_bi(&popped_node, free_token_elem);
			return (FAILURE);
		}
		(*token)->word = concat_dst_to_src(&(*token)->word, append->word);
		if (!(*token)->word)
		{
			ft_lstclear_bi(&popped_node, free_token_elem);
			return (FAILURE);
		}
		if (!append->is_connect_to_next)
			break ;
		ft_lstclear_bi(&popped_node, free_token_elem);
	}
	ft_lstclear_bi(&popped_node, free_token_elem);
	return (SUCCESS);
}

/* connect (*token_list)->content if "is_connect_to_next" */
int	concat_tokens_and_create_wildcard_valid_list(t_list_bi **token_list)
{
	t_list_bi		*node;
	t_token_elem	*token;

	if (!token_list)
		return (FAILURE);
	node = *token_list;
	while (node)
	{
		token = node->content;
		if (get_wildcard_valid_lsit(&token) == FAILURE)
			return (FAILURE);
		node = node->next;
		if (!token->is_connect_to_next)
			continue ;
		concat_connected_words(&node, &token);
		token->is_connect_to_next = false;
	}
	return (SUCCESS);
}
