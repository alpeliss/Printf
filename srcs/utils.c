/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:03:39 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/09 00:35:23 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_atoi(t_env *e, const char *str)
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

int			ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_nbr		find_nbr_stats(t_nbr *nb, long long s_base, t_env *e)
{
	long long	div;

	div = s_base;
	nb->size = 1;
	while (nb->val / div)
	{
		div *= s_base;
		nb->size++;
	}
	nb->sign = (nb->val < 0 || !(e->tags.flags % 3)
							|| !(e->tags.flags % 5)) ? 1 : 0;
	nb->size_aff = (nb->size > e->tags.preci) ? nb->size : e->tags.preci;
	nb->size_aff += nb->sign;
	nb->c_sign = (nb->val < 0) ? '-' : '+';
	nb->c_sign = (nb->val >= 0 && !(e->tags.flags % 5)) ? ' ' : nb->c_sign;
	nb->c_sign = (nb->val >= 0 && !(e->tags.flags % 3)) ? '+' : nb->c_sign;
	if (!nb->val && !e->tags.preci)
		nb->size_aff = 0 + nb->sign;
	return (*nb);
}

static void	mini_putnbr(long long nb, char *base, t_env *e)
{
	if (nb < 0)
		nb = -nb;
	e->value += write(1, &base[nb], 1);
}

void		ft_putnbr_base(long long nb, char *base, long long s_b, t_env *e)
{
	if (nb > -s_b && nb < s_b)
		mini_putnbr(nb, base, e);
	else if (nb > 0)
	{
		ft_putnbr_base(nb / s_b, base, s_b, e);
		ft_putnbr_base(nb % s_b, base, s_b, e);
	}
	else
		ft_putnbr_base(-nb, base, s_b, e);
}
