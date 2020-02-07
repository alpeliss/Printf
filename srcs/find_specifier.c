/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:22:24 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/07 18:54:47 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_specifier(t_env *e, const char *s)
{
	if (s[e->i] == 'l' || s[e->i] == 'h')
	{
		e->i++;
		e->tags.len *= (s[e->i] == 'l') ? 2 : 3;
		return (find_specifier(e, s));
	}
	else if (s[e->i] == 'c')
		return (print_char(e));
	else if (s[e->i] == 's')
		return (print_str(e));
/*
**	else if (s[e->i] == 'p')
**		printf_ptr(e, s);
**	else if (s[e->i] == 'd' || s[e->i] == 'i')
**		return (printf_int(e, s));
**	else if (s[e->i] == 'u' || s[e->i] == 'x' || s[e->i] == 'X'
**			|| s[e->i] == 'o')
**		return (printf_uint(e, s));
*/
	return (0);
}
