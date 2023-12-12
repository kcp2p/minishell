/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wildcard_token_from_dir.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:54:38 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:52 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

/* return true if string consist of `.` and `*`,
 * `.` is the first half and `*` in the second half */
static bool	is_wildcard_includes_hidden(const char *wildcard_str)
{
	if (wildcard_str && wildcard_str[0] == '.')
		return (true);
	return (false);
}

static int	create_wildcard_tokens(t_list_bi **save, \
t_list_bi **popped, const char *wildcard_str, const int *valid_list)
{
	char			*name;
	t_list_bi		*newlist;
	t_token_elem	*token_elem;

	if (!wildcard_str || !popped || !save)
		return (FAILURE);
	name = (*popped)->content;
	if (is_matches_wildcard_and_target_str(wildcard_str, name, valid_list))
	{
		token_elem = create_token_elem(name, false, false, '\0');
		if (!token_elem)
			return (FAILURE);
		newlist = ft_lstnew_bi(token_elem);
		if (!newlist)
		{
			free_token_elem(token_elem);
			return (perror_ret_int("malloc", FAILURE));
		}
		ft_lstadd_back_bi(&(*save), newlist);
		ft_lstdelone_bi(&*popped, NULL);
	}
	else
		ft_lstdelone_bi(&*popped, free);
	return (SUCCESS);
}

static int	get_tokens_match_with_wildcard(t_list_bi **save, \
const char *wildcard_str, t_list_bi *dirlist, const int *valid_list)
{
	char			*name;
	t_list_bi		*popped_node;

	if (!wildcard_str || !dirlist || !save)
		return (FAILURE);
	while (dirlist)
	{
		popped_node = ft_lstpop_bi(&dirlist);
		name = popped_node->content;
		if (!is_wildcard_includes_hidden(wildcard_str) \
		&& name && name[0] == '.')
		{
			ft_lstdelone_bi(&popped_node, free);
			continue ;
		}
		if (create_wildcard_tokens(\
		save, &popped_node, wildcard_str, valid_list) == FAILURE)
		{
			ft_lstdelone_bi(&popped_node, NULL);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	get_wildcard_tokens(t_list_bi **get_tokens_save_to, \
const char *wildcard_str, const int *valid_list)
{
	t_list_bi	*dirlist;

	if (!get_tokens_save_to || !wildcard_str || !valid_list)
		return (FAILURE);
	dirlist = get_read_dir_list();
	if (!dirlist)
		return (FAILURE);
	*get_tokens_save_to = NULL;
	if (get_tokens_match_with_wildcard(\
	get_tokens_save_to, wildcard_str, dirlist, valid_list) == FAILURE)
	{
		ft_lstclear_bi(&dirlist, free);
		return (FAILURE);
	}
	sort_ascending_strlist(&(*get_tokens_save_to));
	return (SUCCESS);
}
