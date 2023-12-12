/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:56:39 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:37:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static void	print_parenthesis_error(int cnt)
{
	if (cnt > 0)
		ft_dprintf(STDERR_FILENO, \
		"minishell: syntax error unclosed parenthesis `('\n");
	else
		ft_dprintf(STDERR_FILENO, \
		"minishell: syntax error unclosed parenthesis `)'\n");
}

int	validate_syntax_parenthesis_pairs(t_list_bi *tokenlist_head)
{
	t_list_bi		*node;
	t_token_elem	*token;
	int				cnt;

	if (!tokenlist_head)
		return (FAILURE);
	node = tokenlist_head;
	cnt = 0;
	while (node)
	{
		token = node->content;
		if (token->type == e_subshell_start)
			cnt++;
		if (token->type == e_subshell_end)
			cnt--;
		node = node->next;
	}
	if (cnt == 0)
		return (SUCCESS);
	print_parenthesis_error(cnt);
	return (FAILURE);
}

static t_token_elem	*get_next_token(t_list_bi *node)
{
	if (!node)
		return (NULL);
	if (node->next)
		return (node->next->content);
	return (NULL);
}

int	validate_syntax_operators(t_list_bi *tokenlist_head)
{
	t_list_bi		*node;
	t_token_elem	*token;
	t_token_elem	*next_token;
	bool			is_head;

	node = tokenlist_head;
	next_token = NULL;
	is_head = true;
	while (node)
	{
		token = node->content;
		next_token = get_next_token(node);
		if (validate_operator_tokens(token, next_token, is_head) == FAILURE)
			return (FAILURE);
		node = node->next;
		is_head = false;
	}
	return (SUCCESS);
}
