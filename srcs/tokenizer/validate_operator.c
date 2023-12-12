/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:56:34 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static void	print_operator_error_msg(char *word)
{
	const size_t	len = ft_strlen_nn(word);
	size_t			minsize;

	if (!word)
		return ;
	minsize = 1;
	if (word[0] == '<')
	{
		if (len == 3)
		{
			ft_dprintf(STDERR_FILENO, \
			"minishell: syntax error near unexpected token `newline'\n");
			return ;
		}
		minsize = 4;
	}
	if (word[0] == '>')
		minsize = 3;
	if (0 < len && len <= minsize)
		ft_dprintf(STDERR_FILENO, \
	"minishell: syntax error near unexpected token `%s'\n", &word[len - 1]);
	else
		ft_dprintf(STDERR_FILENO, \
	"minishell: syntax error near unexpected token `%s'\n", &word[len - 2]);
}

static int	validate_operator_sign(t_token_elem *now_token)
{
	const char	*operators[] = {\
	";", "|", "||", "&&", "(", ")", "<", ">", ">>", "<<", NULL};
	size_t		idx;

	if (!now_token)
		return (FAILURE);
	if (now_token->is_quoted)
		return (SUCCESS);
	if (!is_str1chrs_in_str2(STR_OPERATOR, now_token->word))
		return (SUCCESS);
	idx = 0;
	while (operators[idx])
	{
		if (is_same_str(operators[idx], now_token->word))
			return (SUCCESS);
		idx++;
	}
	print_operator_error_msg(now_token->word);
	return (FAILURE);
}

/*
 validate control sign
 error: <<<, ;;, |||, &&&, etc.
*/
int	valid_control_operator(t_list_bi **tokenlist_head)
{
	t_list_bi		*node;
	t_token_elem	*token;

	node = *tokenlist_head;
	while (node)
	{
		token = node->content;
		if (validate_operator_sign(token) == FAILURE)
			return (FAILURE);
		node = node->next;
	}
	return (SUCCESS);
}
