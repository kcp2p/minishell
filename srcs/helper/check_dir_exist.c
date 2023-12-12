/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir_exist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:56:26 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:56:26 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cd_error(int err_no, char *cmd)
{
	if (err_no == ENOENT)
		ft_printf("minishell: cd: %s: No such file or directory\n", cmd);
	if (err_no == ENOTDIR)
		ft_printf("minishell: cd: %s: Not a directory\n", cmd);
	if (err_no == ETXTBSY)
		ft_printf("minishell: cd: %s: Text file busy\n", cmd);
}

int	check_dir_exist(char *tdir, char *cmd, int print_flag)
{
	DIR		*dir;

	errno = 0;
	dir = opendir(tdir);
	if (dir)
		closedir(dir);
	if (errno == ENOENT || errno == ENOTDIR || errno == ETXTBSY)
	{
		if (print_flag == 1)
			print_cd_error(errno, cmd);
		return (EXIT_FAILURE);
	}
	if (errno == EACCES)
		return (errno);
	return (EXIT_SUCCESS);
}
