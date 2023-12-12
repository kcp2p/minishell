/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_redirect_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:58:49 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:52 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_list_bi	*create_new_redirect_list(\
t_command_info **cmd_list, t_token_elem *token_elem)
{
	t_redirect_info	*redirect_info;
	t_list_bi		*new_redirect_list;

	redirect_info = create_redirect_info(\
	token_elem->type, &(*cmd_list)->pipeline_token_list);
	if (!redirect_info)
		return (NULL);
	new_redirect_list = ft_lstnew_bi(redirect_info);
	if (!new_redirect_list)
	{
		free_redirect_info(redirect_info);
		return (NULL);
	}
	return (new_redirect_list);
}

static int	classify_tokens_save_or_redirect(t_list_bi *popped_node, \
t_token_elem *token_elem, t_list_bi **command_save, t_command_info **cmd_list)
{
	t_list_bi		*new_redirect_list;

	if (!is_tokentype_redirection(token_elem->type))
	{
		ft_lstadd_back_bi(command_save, popped_node);
		return (SUCCESS);
	}
	new_redirect_list = create_new_redirect_list(cmd_list, token_elem);
	ft_lstdelone_bi(&popped_node, free_token_elem);
	if (!new_redirect_list)
	{
		ft_lstclear_bi(command_save, free_token_elem);
		return (FAILURE);
	}
	ft_lstadd_back_bi(&(*cmd_list)->redirect_list, new_redirect_list);
	return (SUCCESS);
}

/* redirect token node clear in function */
static int	create_redirect_list_by_pipeline(t_command_info **cmd_list)
{
	t_list_bi		*popped_node;
	t_token_elem	*token_elem;
	t_list_bi		*command_save;

	if (!cmd_list || !*cmd_list)
		return (FAILURE);
	command_save = NULL;
	while ((*cmd_list)->pipeline_token_list)
	{
		popped_node = ft_lstpop_bi(&(*cmd_list)->pipeline_token_list);
		token_elem = popped_node->content;
		if (classify_tokens_save_or_redirect(\
		popped_node, token_elem, &command_save, cmd_list) == FAILURE)
		{
			ft_lstclear_bi(&command_save, free_token_elem);
			return (FAILURE);
		}
	}
	(*cmd_list)->pipeline_token_list = command_save;
	return (SUCCESS);
}

static int	create_heredoc_eof(t_command_info **cmd_list, t_info *info)
{
	t_list_bi		*node;
	t_redirect_info	*r_info;
	bool			is_quoted;

	if (!cmd_list || !*cmd_list)
		return (FAILURE);
	node = (*cmd_list)->redirect_list;
	while (node)
	{
		r_info = node->content;
		if (r_info->io_type == e_heredoc)
		{
			r_info->heredoc_eof = get_filename_or_heredoc_eof(\
			&r_info->token_list, &is_quoted, false, info);
			if (!r_info->heredoc_eof)
				return (FAILURE);
			if (is_quoted)
				r_info->is_expansion = false;
		}
		node = node->next;
	}
	return (SUCCESS);
}

/* functions */
int	create_redirect_list(t_exec_list **exexlist_head, t_info *info)
{
	t_list_bi		*command_list_node;
	t_command_info	*command_list;
	t_exec_list		*exec_list_node;

	if (!exexlist_head || !*exexlist_head)
		return (FAILURE);
	exec_list_node = *exexlist_head;
	while (exec_list_node)
	{
		command_list_node = exec_list_node->pipeline_commands;
		while (command_list_node)
		{
			command_list = command_list_node->content;
			if (create_redirect_list_by_pipeline(&command_list) == FAILURE)
				return (FAILURE);
			if (create_heredoc_eof(&command_list, info) == FAILURE)
				return (FAILURE);
			command_list_node = command_list_node->next;
		}
		exec_list_node = exec_list_node->next;
	}
	return (SUCCESS);
}
