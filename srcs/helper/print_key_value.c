/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_key_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:56:41 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/10 14:56:42 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_key_value(void *content)
{
	t_env_elem	*elem;

	elem = content;
	if (!elem)
		return ;
	if (elem->value != NULL && elem->not_print == 0)
		ft_printf("%s=%s\n", elem->key, elem->value);
}

void	print_export_key_value(void *content)
{
	t_env_elem	*elem;

	elem = content;
	if (!elem)
		return ;
	if (elem->value != NULL && elem->not_print == 0)
		ft_printf("declare -x %s=\"%s\"\n", elem->key, elem->value);
	else if (elem->not_print == 0)
		ft_printf("declare -x %s\n", elem->key);
}
