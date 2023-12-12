/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:56:44 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:56:44 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err_message(void)
{
	ft_dprintf(STDERR_FILENO, "cd: error retrieving current directory: ");
	ft_dprintf(STDERR_FILENO, "getcwd: cannot access parent directories: ");
	ft_dprintf(STDERR_FILENO, "directories: No such file or directory \n");
}
