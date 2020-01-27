/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:10:57 by alpeliss          #+#    #+#             */
/*   Updated: 2020/01/27 20:25:55 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

static t_env	init_env(void)
{
	t_env		e;

	e.i = 0;
	e.value = 0;
	return (e);
}

int		param_handler(t_env *e, const char *s)
{
	e->i++;
	e->tags = find_tags(e, s);
	printf("flags = %d\nwidth = %d\npreci = %d\n", e->tags.flags, e->tags.width, e->tags.preci);
	return (find_specifer(e, s));
}

int		ft_printf(const char *s, ...)
{
	t_env	e;

	if (!s)
		return (-1);
	e = init_env();
	va_start(e.ap, s);
	while (s[e.i])
	{
		if (s[e.i] == '%' && !param_handler(&e, s))
			return (write(1, "y a un truc qui va pas :\\\n", 27));
		else
		{
			e.value += write(1, &s[e.i], 1);
			e.i++;
		}
	}
	return (e.value);
}
