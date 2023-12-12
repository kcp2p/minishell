/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:56:08 by krchuaip          #+#    #+#             */
/*   Updated: 2023/11/29 18:56:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_token_elem	*create_token_elem(\
char *word, bool is_connected, bool is_quoted, char quote_chr)
{
	t_token_elem	*new_token;

	new_token = (t_token_elem *)malloc(sizeof(t_token_elem));
	if (!new_token)
	{
		free_token_elem(new_token);
		return (perror_ret_nullptr("malloc"));
	}
	new_token->word = word;
	new_token->type = e_init;
	new_token->is_connect_to_next = is_connected;
	new_token->is_quoted = is_quoted;
	new_token->quote_chr = quote_chr;
	new_token->subshell_depth = -1;
	new_token->wildcard_valid_flag = NULL;
	return (new_token);
}
