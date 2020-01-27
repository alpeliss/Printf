/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:13:06 by alpeliss          #+#    #+#             */
/*   Updated: 2020/01/27 20:57:12 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

typedef struct	s_tags
{
	int			flags;
	int			width;
	int			preci;
	int			len;
}				t_tags;

typedef struct	s_env
{
	t_tags		tags;
	int			i;
	int			value;
	va_list		ap;
}				t_env;

int		ft_printf(const char *s, ...);
t_tags	find_tags(t_env *e, const char *s);
int		ft_printf_atoi(t_env *e, const char *str);
int		find_specifier(t_env *e, const char *s)

#endif
