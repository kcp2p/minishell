/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:24 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_execution.h"

bool	is_delimiter(const char *input_line, const char *delimiter)
{
	size_t	input_len;
	size_t	delim_len;

	if (!input_line || !delimiter)
		return (false);
	input_len = ft_strlen_nn(input_line);
	delim_len = ft_strlen_nn(delimiter);
	if ((input_len == delim_len + 1)
		&& ft_strncmp_nn(input_line, delimiter, delim_len) == 0)
		return (true);
	return (false);
}

bool	is_eof(char *line)
{
	return (!line);
}

/* tmp file name is "heredoc_<cnt>.tmp" */
char	*get_heredoc_tmp_filename(int cnt)
{
	char	*cnt_string;
	char	*filename;
	size_t	tmp_len;
	size_t	strcnt_len;

	errno = 0;
	cnt_string = ft_itoa(cnt);
	if (!cnt_string)
		return (perror_ret_nullptr("malloc"));
	tmp_len = ft_strlen_nn(HEREDOC_TMP_FILE);
	strcnt_len = ft_strlen_nn(cnt_string);
	filename = (char *)ft_calloc(sizeof(char), (tmp_len + strcnt_len + 1));
	if (!filename)
		return (perror_ret_nullptr("malloc"));
	ft_strlcat(filename, HEREDOC_TMP_FILE, tmp_len + strcnt_len + 1);
	ft_strlcat(filename, cnt_string, tmp_len + strcnt_len + 1);
	free(cnt_string);
	return (filename);
}
