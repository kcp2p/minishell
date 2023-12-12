/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:55:28 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:55:29 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cd_info	*init_cd_info(t_info *info, char *cmd)
{
	t_cd_info	*cd_info;

	cd_info = malloc(sizeof(t_cd_info));
	if (!cd_info)
		return (NULL);
	cd_info->cd_type = e_cd_init;
	cd_info->home = get_elem(info, "HOME");
	cd_info->cdpath = get_elem(info, "CDPATH");
	cd_info->env_pwd = get_elem(info, "PWD");
	cd_info->pwd = getcwd(NULL, 0);
	if (cd_info->pwd == NULL && check_dir_exist("./", cmd, 1) == EACCES)
		cd_info->pwd = ft_strdup(*get_elem(info, "PWD"));
	cd_info->oldpwd = get_elem(info, "OLDPWD");
	cd_info->newpwd = NULL;
	cd_info->cur_pwd = NULL;
	return (cd_info);
}

int	ft_cd(t_info *info, char **cmds)
{
	int			exit_status;
	t_cd_info	*cd_info;

	exit_status = EXIT_SUCCESS;
	if (!info || !cmds)
		return (EXIT_FAILURE);
	cd_info = init_cd_info(info, cmds[1]);
	if (!cd_info)
		return (perror_and_return_int("malloc", EXIT_FAILURE));
	cd_info->cd_type = judge_cmd(*(++cmds));
	if (cd_error_handler(cd_info, cmds) == EXIT_FAILURE)
		return (free_cdinfo_ret_status(cd_info, EXIT_FAILURE));
	cd_info->newpwd = define_new_path(cd_info, *cmds);
	if (!cd_info->newpwd)
		return (perror_and_return_int("malloc", EXIT_FAILURE));
	exit_status = chdir_setpath(info, cd_info, cmds);
	return (free_cdinfo_ret_status(cd_info, exit_status));
}
