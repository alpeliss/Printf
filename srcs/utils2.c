/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:27:08 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/11 00:27:30 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_nbr		find_unbr_stats(t_nbr *nb, unsigned long long s_base, t_env *e)
{
	unsigned long long	div;

	div = s_base;
	nb->size = 1;
	nb->sign = (!(e->tags.flags % 7) && nb->u_val) ? 2 : 0;
	nb->sign = (!(e->tags.flags % 7) && s_base == 8 &&
			(e->tags.preci != -1 || nb->u_val)) ? 1 : nb->sign;
	while (div && nb->u_val / div)
	{
		div *= s_base;
		nb->size++;
	}
	if (s_base == 16)
	{
		nb->size_aff = (nb->size > e->tags.preci) ? nb->size : e->tags.preci;
		nb->size_aff += nb->sign;
	}
	else
		nb->size_aff = (nb->size + nb->sign > e->tags.preci) ?
			nb->size + nb->sign : e->tags.preci;
	if (nb->sign == 1)
		nb->size++;
	if (!nb->u_val && !e->tags.preci)
		nb->size_aff = 0 + nb->sign;
	return (*nb);
}

void		ft_putunbr_base(unsigned long long nb, char *base,
		unsigned long long s_b, t_env *e)
{
	if (nb < s_b)
		e->value += write(1, &base[nb], 1);
	else if (nb > 0)
	{
		ft_putnbr_base(nb / s_b, base, s_b, e);
		ft_putnbr_base(nb % s_b, base, s_b, e);
	}
}
