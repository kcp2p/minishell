/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tokens_to_command_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:58:54 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:52 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	move_tokens_to_cmd_info(\
t_list_bi **tok_lst, t_command_info **cmd_lst, t_list_bi *popped_tok)
{
	t_token_elem	*token_elem;

	if (!tok_lst || !cmd_lst || !popped_tok)
		return ;
	token_elem = popped_tok->content;
	if (is_tokentype_subshell(token_elem->type))
		move_tokens_to_subshell_list(tok_lst, cmd_lst, popped_tok);
	else
		move_tokens_to_pipeline_list(cmd_lst, popped_tok);
}

void	move_tokens_to_subshell_list(
		t_list_bi **tok_lst, t_command_info **cmd_lst, t_list_bi *popped_tok)
{
	t_token_elem	*token_elem;
	ssize_t			subshell_depth;

	if (!tok_lst || !cmd_lst || !popped_tok)
		return ;
	token_elem = popped_tok->content;
	(*cmd_lst)->type = e_node_subshell;
	subshell_depth = token_elem->subshell_depth;
	ft_lstdelone_bi(&popped_tok, free_token_elem);
	while (*tok_lst)
	{
		popped_tok = ft_lstpop_bi(&(*tok_lst));
		token_elem = popped_tok->content;
		if (token_elem->type == e_subshell_end \
		&& token_elem->subshell_depth == subshell_depth)
		{
			ft_lstdelone_bi(&popped_tok, free_token_elem);
			return ;
		}
		ft_lstadd_back_bi(&(*cmd_lst)->subshell_token_list, popped_tok);
	}
}

void	move_tokens_to_pipeline_list(
		t_command_info **command_list, t_list_bi *popped_token)
{
	if (!command_list || !popped_token)
		return ;
	if ((*command_list)->type == e_node_init)
		(*command_list)->type = e_node_pipeline;
	ft_lstadd_back_bi(&(*command_list)->pipeline_token_list, popped_token);
}
