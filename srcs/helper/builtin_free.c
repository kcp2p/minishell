/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:56:34 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:56:35 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	perror_and_return_int(char *err, int exit_status)
{
	perror(err);
	return (exit_status);
}

int	free_cdinfo_ret_status(t_cd_info *cd_info, int exit_status)
{
	if (cd_info->pwd != NULL)
		free(cd_info->pwd);
	if (cd_info->newpwd != NULL)
		free(cd_info->newpwd);
	free(cd_info);
	return (exit_status);
}

int	cd_error_handler(t_cd_info *cd_info, char **cmds)
{
	if (cd_info->cd_type == e_opt_error)
	{
		ft_printf("minishell: cd: %c%c: invalid option\n", (*cmds)[0], \
		(*cmds)[1]);
		return (EXIT_FAILURE);
	}
	else if (cd_info->cd_type == e_oldpwd && \
	(cd_info->oldpwd == NULL || *(cd_info->oldpwd) == NULL))
	{
		ft_printf("minishell: cd: OLDPWD not set\n");
		return (EXIT_FAILURE);
	}
	else if (cd_info->cd_type == e_home && cd_info->home == NULL)
	{
		ft_printf("minishell: cd: HOME not set\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	init_key_value(t_export_info *e_info)
{
	if (e_info != NULL)
	{
		e_info->key = NULL;
		e_info->value = NULL;
		e_info->key_type = e_typeinit;
	}
}
