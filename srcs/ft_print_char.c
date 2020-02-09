/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:33:30 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/08 21:07:51 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(t_env *e)
{
	long long int	c;
	int				i;
	char			fill;

	fill = (e->tags.flags % 11) ? ' ' : '0';
	c = va_arg(e->ap, int);
	i = 0;
	if (e->tags.flags % 2)
		while (++i < e->tags.width)
			e->value += write(1, &fill, 1);
	e->value += write(1, &c, 1);
	while (++i < e->tags.width)
		e->value += write(1, " ", 1);
	e->i++;
	return (1);
}
