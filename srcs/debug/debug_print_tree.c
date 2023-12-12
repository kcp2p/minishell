/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:53:14 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:53:15 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_node(t_exec_list *node)
{
	const char	*type[] = {";", "|", "||", "&&", "(", ")", \
	"<", ">", ">>", "<<", "file", "eof", "word", "init", NULL};
	t_exec_list	*left_node;

	if (node->node_kind == e_node_pipeline)
	{
		ft_dprintf(STDERR_FILENO, "[pipeline_commands] :");
		debug_print_tokens(node->token_list_head, NULL);
	}
	else
	{
		left_node = node->prev;
		ft_dprintf(STDERR_FILENO, "[pipeline_commands] :");
		debug_print_tokens(left_node->token_list_head, NULL);
		if (node->node_kind != e_node_head)
			ft_dprintf(STDERR_FILENO, "[%s]\n  |\n", type[node->token_type]);
	}
}

void	debug_print_tree(t_exec_list *root, char *str)
{
	t_exec_list	*node;

	if (str)
		ft_dprintf(STDERR_FILENO, "#%-15s\n", str);
	if (!root)
	{
		ft_dprintf(STDERR_FILENO, "tree node is null\n");
		return ;
	}
	ft_dprintf(STDERR_FILENO, "[root]\n  |\n");
	node = root;
	while (node)
	{
		print_node(node);
		node = node->next;
	}
}
