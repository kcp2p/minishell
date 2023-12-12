/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_operator_list_helper.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:58:46 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:52 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_pipeline_token(t_token_elem *token_elem, ssize_t	subshell_depth)
{
	if (!token_elem)
		return (false);
	if (!(is_tokentype_operator(token_elem->type) \
	&& token_elem->subshell_depth == subshell_depth))
		return (true);
	return (false);
}

void	delete_operator_token(t_list_bi **operator_token)
{
	if (!operator_token || !*operator_token)
		return ;
	ft_lstdelone_bi(operator_token, free_token_elem);
	*operator_token = NULL;
}
