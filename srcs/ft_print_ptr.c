/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:14:57 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/12 18:56:42 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_addr(void *addr, int print)
{
	long long	add_val;
	long long	div;
	char		c;
	int			size;

	size = 0;
	add_val = (long long)addr;
	div = 16;
	while (add_val / div)
		div *= 16;
	div /= 16;
	while (div)
	{
		c = (add_val / div < 10) ? add_val / div
			+ '0' : add_val / div + 'a' - 10;
		if (print)
			write(1, &c, 1);
		size++;
		add_val = add_val % div;
		div = div / 16;
	}
	return (size);
}

int			print_ptr(t_env *e, int i)
{
	void			*addr;
	int				len;
	char			fill;

	addr = va_arg(e->ap, void *);
	fill = (e->tags.flags % 11) ? ' ' : '0';
	len = print_addr(addr, 0);
	while (e->tags.flags % 2 && e->tags.flags % 11
			&& ++i < e->tags.width - len - 1)
		e->value += write(1, &fill, 1);
	e->value += write(1, "0x", 2);
	while (e->tags.flags % 2 && ++i < e->tags.width - len - 1)
		e->value += write(1, &fill, 1);
	while (e->tags.preci > len)
	{
		e->value += write(1, "0", 1);
		e->tags.preci--;
	}
	if (addr || e->tags.preci)
		e->value += print_addr(addr, 1);
	while (++i < e->tags.width - len - 1)
		e->value += write(1, " ", 1);
	e->i++;
	return (1);
}
