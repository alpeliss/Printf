/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:37:03 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/12 14:52:14 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(t_env *e)
{
	char	*str;
	int		i;
	int		len;
	char	fill;

	str = va_arg(e->ap, char *);
	len = (str) ? ft_strlen(str) : 6;
	len = (e->tags.preci < len && e->tags.preci != -1) ? e->tags.preci : len;
	fill = (e->tags.flags % 11) ? ' ' : '0';
	i = 0;
	if (e->tags.flags % 2)
		while (++i < e->tags.width - len + 1)
			e->value += write(1, &fill, 1);
	e->value += (str) ? write(1, str, len) : write(1, "(null)", len);
	while (++i < e->tags.width - len + 1)
		e->value += write(1, " ", 1);
	e->i++;
	return (1);
}
