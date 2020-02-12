/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:32:39 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/12 16:01:41 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percent(t_env *e)
{
	int		i;
	char	fill;

	e->i++;
	fill = (e->tags.flags % 11) ? ' ' : '0';
	i = 0;
	if (e->tags.flags % 2)
		while (++i < e->tags.width)
			e->value += write(1, &fill, 1);
	e->value += write(1, "%", 1);
	while (++i < e->tags.width)
		e->value += write(1, " ", 1);
	return (1);
}
