/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:03:39 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/05 14:04:41 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_atoi(t_env *e, const char *str)
{
	long	tot;

	tot = 0;
	while (str[e->i] >= '0' && str[e->i] <= '9')
	{
		tot = tot * 10 + (str[e->i] - '0');
		e->i++;
		if (tot < 0)
			return (0);
	}
	return ((int)tot);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
