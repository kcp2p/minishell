/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:55:51 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:55:52 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_info *info, char **cmds)
{
	char	**value;

	if (!info || !cmds)
		return (EXIT_FAILURE);
	if (cmds[1])
	{
		if (is_same_str(cmds[1], "PWD") == SUCCESS)
		{
			value = get_elem(info, "PWD");
			if (value != NULL)
			{
				ft_dprintf(STDERR_FILENO, "%s\n", *value);
				return (EXIT_SUCCESS);
			}
		}
		ft_dprintf(STDERR_FILENO,
			"env: %s: No such file or directory\n", cmds[1]);
		return (EXIT_FAILURE);
	}
	ft_lstiter(info->envlist_head, print_key_value);
	return (EXIT_SUCCESS);
}

int	ft_sort_env(t_info *info)
{
	if (!info)
		return (EXIT_FAILURE);
	ft_lst_ascsort(&info->envlist_head);
	ft_lstiter(info->envlist_head, print_export_key_value);
	return (EXIT_SUCCESS);
}
