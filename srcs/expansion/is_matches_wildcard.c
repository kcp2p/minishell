/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_matches_wildcard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:54:32 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 20:03:09 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static void	update_dp_table_if_wildcard(int ***dp, size_t i, size_t j)
{
	if (!dp || !*dp)
		return ;
	(*dp)[i][j] = max_int((*dp)[i][j], (*dp)[i - 1][j]);
	if (j > 0)
		(*dp)[i][j] = max_int((*dp)[i][j], (*dp)[i][j - 1]);
}

static int	is_match(const char *wildcard, const char *target, \
int **dp, const int *valid_table)
{
	const size_t	len_wildcard = ft_strlen_nn(wildcard);
	const size_t	len_target = ft_strlen_nn(target);
	size_t			i;
	size_t			j;

	if (!dp || !*dp)
		return (false);
	dp[0][0] = 1;
	i = 1;
	while (i < len_wildcard + 1)
	{
		j = 0;
		while (j < len_target + 1)
		{
			if (valid_table[i - 1] == 1)
				update_dp_table_if_wildcard(&dp, i, j);
			if (j > 0 && valid_table[i - 1] == 0 \
			&& wildcard[i - 1] == target[j - 1])
				dp[i][j] = max_int(dp[i][j], dp[i - 1][j - 1]);
			j++;
		}
		i++;
	}
	return (dp[len_wildcard][len_target] > 0);
}

static int	**get_dp_table(size_t row, size_t col)
{
	int		**dp;
	size_t	idx;

	dp = (int **)ft_calloc(sizeof(int *), row + 1);
	if (!dp)
		return (perror_ret_nullptr("malloc"));
	idx = 0;
	while (idx < row)
	{
		dp[idx] = (int *)ft_calloc(sizeof(int), col + 1);
		if (!dp[idx])
			return (perror_ret_nullptr("malloc"));
		idx++;
	}
	return (dp);
}

static void	free_dp_array(int **dp, size_t row_size)
{
	size_t	i;

	if (!dp || !*dp)
		return ;
	i = 0;
	while (i < row_size)
	{
		free_ret_nullprt(dp[i]);
		i++;
	}
	free(dp);
}

/* return true if wildcard_str matches str */
/* dp[i][j] = 1 or 0
 * if matches wildcard[i] and target[j], dp[i][j] is 1 otherwise 0 */
int	is_matches_wildcard_and_target_str(\
const char *wildcard_str, const char *target_str, const int *valid_table)
{
	const size_t	len_wildcard = ft_strlen_nn(wildcard_str);
	const size_t	len_target = ft_strlen_nn(target_str);
	int				**dp;
	int				ans;

	if (!target_str || !wildcard_str || !valid_table)
		return (false);
	dp = get_dp_table(len_wildcard + 1, len_target + 1);
	if (!dp)
		return (PROCESS_ERROR);
	ans = is_match(wildcard_str, target_str, dp, valid_table);
	free_dp_array(dp, len_wildcard + 1);
	return (ans);
}
