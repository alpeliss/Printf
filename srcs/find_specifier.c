/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:22:24 by alpeliss          #+#    #+#             */
/*   Updated: 2020/01/27 20:56:01 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_specifier(t_env *e, const char *s)
{	
	if (s[e->i] == 'c')
		return (printf_put_char(e, s));
	else if (s[e->i] == 's')
		return (printf_put_str(e, s));
	else if (s[e->i] == 'p')
		printf_put_ptr(e, s);
	else if (s[e->i] == 'd' || s[e->i] == 'i')
		return (printf_put_int(e, s));
	else if (s[e->i] == 'u' || s[e->i] == 'x' || s[e->i] == 'X'
			|| s[e->i] == 'o')
		return (printf_put_uint(e, s));
	else if (s[e->i] =)
		return (printf_put_uint(e, s));
}
