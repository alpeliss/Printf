/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:14:47 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/11 00:29:22 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		size_base(char specif)
{
	if (specif == 'x' || specif == 'X')
		return (16);
	if (specif == 'o')
		return (8);
	if (specif == 'b')
		return (2);
	return (10);
}

static char		*string_base(char specif)
{
	if (specif == 'x')
		return ("0123456789abcdef");
	if (specif == 'X')
		return ("0123456789ABCDEF");
	if (specif == 'o')
		return ("01234567");
	if (specif == 'b')
		return ("01");
	return ("0123456789");
}

static t_nbr	get_nb(t_env *e, char specif)
{
	t_nbr		nb;

	nb.u_val = 0;
	if (e->tags.len == 1)
		nb.u_val = (long long)va_arg(e->ap, unsigned int);
	else if (e->tags.len == 2)
		nb.u_val = (long long)va_arg(e->ap, unsigned long);
	else if (e->tags.len == 4)
		nb.u_val = va_arg(e->ap, unsigned long long);
	else if (e->tags.len == 3)
		nb.u_val = (long long)va_arg(e->ap, unsigned int);
	else if (e->tags.len == 9)
		nb.u_val = (long long)va_arg(e->ap, unsigned int);
	find_unbr_stats(&nb, size_base(specif), e);
	return (nb);
}

static int		pre(char specif)
{
	if (specif == 'x')
		return (write(1, "0x", 2));
	if (specif == 'X')
		return (write(1, "0X", 2));
	if (specif == 'o')
		return (write(1, "0", 1));
	return (0);
}

int				print_uint(t_env *e, char specif)
{
	t_nbr	nb;
	char	fill;
	int		i;

	nb = get_nb(e, specif);
	e->i++;
	fill = (!(e->tags.flags % 11) && e->tags.preci == -1) ? '0' : ' ';
	i = 0;
	if (nb.sign && fill == '0')
		e->value += pre(specif);
	while (e->tags.flags % 2 && i++ < e->tags.width - nb.size_aff)
		e->value += write(1, &fill, 1);
	if (nb.sign && fill == ' ')
		e->value += pre(specif);
	while (e->tags.preci > nb.size)
	{
		e->value += write(1, "0", 1);
		e->tags.preci--;
	}
	if (nb.u_val || e->tags.preci)
		ft_putunbr_base(nb.u_val, string_base(specif), size_base(specif), e);
	while (i++ < e->tags.width - nb.size_aff)
		e->value += write(1, " ", 1);
	return (1);
}
