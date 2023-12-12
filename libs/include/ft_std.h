/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:23:24 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:23:26 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STD_H
# define FT_STD_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# include "ft_string.h"

/* itoa atoi */
char		*ft_itoa(int n);
int			ft_atoi(const char *str, bool *is_success);
long long	ft_strtoll(char *num, bool *is_success);
void		*ft_calloc(size_t count, size_t size);

#endif //FT_STD_H
