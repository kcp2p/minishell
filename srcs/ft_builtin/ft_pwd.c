/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:55:40 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:55:41 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_info *info)
{
	char	*cwd_pwd;
	char	**env_pwd;

	if (!info)
		return (EXIT_FAILURE);
	cwd_pwd = getcwd(NULL, 0);
	if (!cwd_pwd)
	{
		env_pwd = get_elem(info, "PWD");
		if (env_pwd != NULL)
			ft_printf("%s\n", *env_pwd);
		else
			return (perror_and_return_int("getcwd", EXIT_FAILURE));
	}
	else
		ft_printf("%s\n", cwd_pwd);
	free(cwd_pwd);
	return (EXIT_SUCCESS);
}
