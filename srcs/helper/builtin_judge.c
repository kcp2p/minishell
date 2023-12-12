/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_judge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:56:31 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:56:32 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	judge_chr_key(char *key)
{
	if (ft_isdigit(*key) || *key == '\0')
		return (FAILURE);
	while (*key != '\0')
	{
		if (!ft_isalnum(*key) && *key != '_')
			return (FAILURE);
		key++;
	}
	return (SUCCESS);
}

t_key_type	judge_info_key(t_export_info *e_info)
{
	ssize_t	i;
	ssize_t	key_len;
	char	*key;

	i = 0;
	key = e_info->key;
	if (!key)
		return (e_nokey);
	if (ft_isdigit(*key) || *key == '\0')
		return (e_error);
	key_len = ft_strlen(key);
	while (*key)
	{
		if ((i + 1) == key_len && *key == '+' && i == 0)
			return (e_nokey);
		if ((i + 1) == key_len && *key == '+' && e_info->key_type != e_novalue)
			return (e_append);
		if (!ft_isalnum(*key) && *key != '_')
			return (e_error);
		i++;
		key++;
	}
	if (e_info->key_type == e_novalue)
		return (e_novalue);
	return (e_add);
}

t_key_type	judge_value(t_export_info *e_info)
{
	char	*c_ptr;

	c_ptr = e_info->value;
	if (!e_info->value)
		return (e_novalue);
	while (*c_ptr != '\0')
	{
		if (!ft_isprint(*c_ptr))
			return (e_error);
		c_ptr++;
	}
	return (e_info->key_type);
}

int	judge_opt(char *cmd)
{
	if (*(++cmd) != '\0')
		return (e_opt_error);
	return (e_oldpwd);
}

int	judge_cmd(char *cmd)
{
	if (cmd == NULL || is_same_str("--", cmd))
		return (e_home);
	else if (cmd[0] == '-')
		return (judge_opt(cmd));
	else if (cmd[0] == '/')
		return (e_absolute);
	else if (cmd[0] == '.')
		return (e_relative);
	return (e_nomal);
}
