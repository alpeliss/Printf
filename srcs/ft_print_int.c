/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:00:15 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/12 18:48:45 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_nbr	get_nb(t_env *e)
{
	t_nbr		nb;
	short		a;

	nb.val = (e->tags.len != 1) ? 0 : (long long)va_arg(e->ap, int);
	nb.val = (e->tags.len != 2) ? nb.val : (long long)va_arg(e->ap, long);
	nb.val = (e->tags.len != 4) ? nb.val : va_arg(e->ap, long long);
	nb.val = (e->tags.len != 3) ? nb.val : (long long)va_arg(e->ap, int);
	nb.val = (e->tags.len != 9) ? nb.val : (long long)va_arg(e->ap, int);
	if (e->tags.len == 3)
	{
		a = (short)nb.val;
		nb.val = (long long)a;
	}
	if (e->tags.len == 9)
	{
		while (nb.val < -128)
			nb.val += 256;
		while (nb.val > 127)
			nb.val -= 256;
	}
	find_nbr_stats(&nb, 10, e);
	return (nb);
}

int				print_int(t_env *e)
{
	t_nbr	nb;
	char	fill;
	int		i;

	nb = get_nb(e);
	e->i++;
	fill = (!(e->tags.flags % 11) && e->tags.preci <= -1) ? '0' : ' ';
	if (nb.sign && fill == '0')
		e->value += write(1, &nb.c_sign, 1);
	i = 0;
	while (e->tags.flags % 2 && i++ < e->tags.width - nb.size_aff)
		e->value += write(1, &fill, 1);
	if (nb.sign && fill == ' ')
		e->value += write(1, &nb.c_sign, 1);
	while (e->tags.preci > nb.size)
	{
		e->value += write(1, "0", 1);
		e->tags.preci--;
	}
	if (nb.val || e->tags.preci)
		ft_putnbr_base(nb.val, "0123456789", 10, e);
	while (i++ < e->tags.width - nb.size_aff)
		e->value += write(1, " ", 1);
	return (1);
}
