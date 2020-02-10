/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:22:24 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/11 00:28:19 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_specifier(t_env *e, const char *s)
{
	if (s[e->i] == 'l' || s[e->i] == 'h')
	{
		e->tags.len *= (s[e->i] == 'l') ? 2 : 3;
		e->i++;
		return (find_specifier(e, s));
	}
	else if (s[e->i] == 'c')
		return (print_char(e));
	else if (s[e->i] == 's')
		return (print_str(e));
	else if (s[e->i] == '%')
		return (print_percent(e));
	else if (s[e->i] == 'd' || s[e->i] == 'i')
		return (print_int(e));
	else if (s[e->i] == 'u' || s[e->i] == 'x' || s[e->i] == 'X'
			|| s[e->i] == 'o')
		return (print_uint(e, s[e->i]));
	return (0);
}
