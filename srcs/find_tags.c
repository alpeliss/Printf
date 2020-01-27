/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:44:10 by alpeliss          #+#    #+#             */
/*   Updated: 2020/01/27 19:43:46 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_tags	init_tags()
{
	t_tags	tags;

	tags.flags = 1;
	tags.width = 0;
	tags.preci = 1;
	tags.len = 0;
	return (tags);
}

static int		get_num_value(t_env *e, const char *s)
{	
	int	val;

	if ((val = ft_printf_atoi(e, s)) > 0 || s[e->i] == '*')
	{
		if (val)
			return (val);
		e->i++;
		return (va_arg(e->ap, int));
	}
	return (0);
}

t_tags			find_tags(t_env *e, const char *s)
{
	t_tags	tags;

	tags = init_tags();
	while (s[e->i] == '-' || s[e->i] == '+' || s[e->i] == ' ' 
			|| s[e->i] == '#' || s[e->i] == '0')
	{
		tags.flags *= (s[e->i] == '-' && tags.flags % 2) ? 2 : 1;
		tags.flags *= (s[e->i] == '+' && tags.flags % 3) ? 3 : 1;
		tags.flags *= (s[e->i] == ' ' && tags.flags % 5) ? 5 : 1;
		tags.flags *= (s[e->i] == '#' && tags.flags % 7) ? 7 : 1;
		tags.flags *= (s[e->i] == '0' && tags.flags % 11) ? 11 : 1;
		e->i++;
	}
	tags.width = get_num_value(e, s);
	if (s[e->i] == '.')
	{
		e->i++;
		write(1, "EEE\n", 4);
		tags.preci = get_num_value(e, s);
	}
	return (tags);
}
