/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:53:11 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:37:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_2d_arr(char **arr, char *str)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	if (str)
		ft_dprintf(STDERR_FILENO, "#%-15s:", str);
	ft_dprintf(STDERR_FILENO, "{");
	while (arr[i])
	{
		ft_dprintf(STDERR_FILENO, "\"%s\"", arr[i++]);
		if (arr[i])
			ft_dprintf(STDERR_FILENO, ", ");
		else
		{
			if (i > 0)
				ft_dprintf(STDERR_FILENO, ", ");
			ft_dprintf(STDERR_FILENO, "NULL}\n");
		}
	}
}

static void	print_content(t_list_bi **node)
{
	t_redirect_info	*info;
	char			*is_expansion;
	const char		*type[] = {";", "|", "||", "&&", "(", ")", \
	"<", ">", ">>", "<<", "f", "e", "w", "i", NULL};

	info = (*node)->content;
	ft_dprintf(STDERR_FILENO, "%s[", type[info->io_type]);
	if (info->io_type == e_heredoc)
	{
		if (info->is_expansion)
			is_expansion = "y";
		else
			is_expansion = "n";
		ft_dprintf(STDERR_FILENO, "heredoc eof:%s, file:%s]%s", \
			info->heredoc_eof, info->filename, is_expansion);
	}
	else
		ft_dprintf(STDERR_FILENO, "filename:%s]", info->filename);
	*node = (*node)->next;
	if (*node)
		ft_dprintf(STDERR_FILENO, ", ");
	else
		ft_dprintf(STDERR_FILENO, "\n");
}

void	debug_print_redirect_info(t_list_bi *head, char *str)
{
	t_list_bi		*node;

	if (str)
		ft_dprintf(STDERR_FILENO, "#%-15s:", str);
	node = head;
	while (node)
		print_content(&node);
}

void	debug_print_env(t_list *envlist)
{
	t_env_elem	*env_elem;

	if (!envlist)
	{
		ft_printf("(null)\n");
		return ;
	}
	while (envlist)
	{
		env_elem = envlist->content;
		if (!env_elem)
			ft_printf("content: (null)\n");
		else
			ft_printf("key: %s, value:%s\n", env_elem->key, env_elem->value);
		envlist = envlist->next;
	}
}
