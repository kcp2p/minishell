/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:55:05 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:52 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static int	do_expand(t_list_bi **popped_node, \
t_list_bi **wildcard_save_list, t_list_bi **expanded_tokens)
{
	t_token_elem	*token_elem;

	token_elem = (*popped_node)->content;
	if (get_wildcard_tokens(wildcard_save_list, \
	token_elem->word, token_elem->wildcard_valid_flag) == FAILURE)
	{
		ft_lstclear_bi(wildcard_save_list, free);
		ft_lstdelone_bi(popped_node, free_token_elem);
		ft_lstclear_bi(expanded_tokens, free_token_elem);
		return (FAILURE);
	}
	if (ft_lstsize_bi(*wildcard_save_list) != 0)
	{
		ft_lstdelone_bi(popped_node, free_token_elem);
		*popped_node = *wildcard_save_list;
	}
	return (SUCCESS);
}

bool	is_not_expandable_command(t_list_bi *first_token)
{
	t_token_elem	*token_elem;

	if (!first_token)
		return (false);
	token_elem = first_token->content;
	return (is_same_str("export", token_elem->word));
}

/*
 if character * is wildcard, it is expanded to match string.
 if character "*" is string, it is not expanded.
 */
int	expanded_wildcard_to_token_list(t_list_bi **token_list)
{
	t_list_bi		*expanded_tokens;
	t_list_bi		*popped_node;
	t_token_elem	*token_elem;
	t_list_bi		*wildcard_match_tokens;

	if (!token_list)
		return (FAILURE);
	if (is_not_expandable_command(*token_list))
		return (SUCCESS);
	expanded_tokens = NULL;
	while (*token_list)
	{
		popped_node = ft_lstpop_bi(&(*token_list));
		token_elem = popped_node->content;
		if (check_valid_wildcard_in_word(token_elem))
			if (do_expand(&popped_node, \
			&wildcard_match_tokens, &expanded_tokens) == FAILURE)
				return (FAILURE);
		ft_lstadd_back_bi(&expanded_tokens, popped_node);
	}
	*token_list = expanded_tokens;
	return (SUCCESS);
}
