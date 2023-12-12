/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:28:28 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:28:28 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret_str;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	ret_str = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (ret_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret_str[i] = f(i, s[i]);
		i++;
	}
	return (ret_str);
}
