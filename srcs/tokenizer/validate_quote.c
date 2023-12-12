/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:56:36 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	validate_quote(t_list_bi *tokenlist_head)
{
	t_list_bi		*node;
	t_token_elem	*now_token;
	size_t			word_len;
	char			*word;

	if (!tokenlist_head)
		return (FAILURE);
	node = tokenlist_head;
	while (node)
	{
		now_token = node->content;
		if (now_token->is_quoted)
		{
			word = now_token->word;
			word_len = ft_strlen_nn(word);
			if (word_len < 2 || word[0] != word[word_len - 1])
			{
				ft_dprintf(STDERR_FILENO, \
				"minishell: unclosed quote `%c'\n", now_token->word[0]);
				return (FAILURE);
			}
		}
		node = node->next;
	}
	return (SUCCESS);
}
