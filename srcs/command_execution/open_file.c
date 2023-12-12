/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:10 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:52:11 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_execution.h"

int	get_openfile_fd(const char *filename, t_fopen fopen_type)
{
	if (fopen_type == e_io_read)
		return (open(filename, O_RDONLY));
	if (fopen_type == e_io_overwrite)
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	return (open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644));
}

t_fopen	get_fopen_type(t_token_type io_type)
{
	if (io_type == e_redirect_in || io_type == e_heredoc)
		return (e_io_read);
	if (io_type == e_redirect_out)
		return (e_io_overwrite);
	return (e_io_append);
}

int	get_io_fd(t_token_type io_type)
{
	if (io_type == e_redirect_in || io_type == e_heredoc)
		return (FD_INFILE);
	return (FD_OUTFILE);
}
