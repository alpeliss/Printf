/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:36:05 by alpeliss          #+#    #+#             */
/*   Updated: 2020/01/27 19:38:53 by alpeliss         ###   ########.fr       */
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
