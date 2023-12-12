/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:57:03 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:57:04 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	perror_ret_int(char *err, int retno)
{
	perror(err);
	return (retno);
}

void	*perror_ret_nullptr(char *err)
{
	perror(err);
	return (NULL);
}

int	ambiguous_error(char *filename)
{
	ft_dprintf(STDERR_FILENO, ERRMSG_AMBIGUOUS, filename);
	return (FAILURE);
}

int	openfile_error(char *filename, char *strerror)
{
	ft_dprintf(STDERR_FILENO, ERRMSG_FILEOPEN, filename, strerror);
	return (FAILURE);
}
