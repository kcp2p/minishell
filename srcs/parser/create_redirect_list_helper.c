/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_redirect_list_helper.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:59:00 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:52 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* token node filename or heredoc eof is cleared in function */
static t_list_bi	*get_filename_or_eof_tokenlist(t_list_bi **token_get_from)
{
	t_list_bi		*token_list;
	t_list_bi		*popped_token_node;
	t_token_elem	*token_elem;

	if (!token_get_from || !*token_get_from)
		return (NULL);
	token_list = NULL;
	while (*token_get_from)
	{
		popped_token_node = ft_lstpop_bi(token_get_from);
		token_elem = popped_token_node->content;
		ft_lstadd_back_bi(&token_list, popped_token_node);
		if (!token_elem->is_connect_to_next)
			break ;
	}
	return (token_list);
}

t_redirect_info	*create_redirect_info(\
t_token_type io_type, t_list_bi **token_list)
{
	t_redirect_info	*redirect_info;

	if (!token_list || !*token_list)
		return (NULL);
	errno = 0;
	redirect_info = (t_redirect_info *)malloc(sizeof(t_redirect_info));
	if (!redirect_info)
		return (perror_ret_nullptr("malloc"));
	redirect_info->io_type = io_type;
	redirect_info->filename = NULL;
	redirect_info->heredoc_eof = NULL;
	redirect_info->is_expansion = true;
	redirect_info->is_ambiguous = false;
	redirect_info->token_list = get_filename_or_eof_tokenlist(token_list);
	return (redirect_info);
}
