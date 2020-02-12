/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:13:06 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/12 14:16:17 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_tags
{
	int					flags;
	int					width;
	int					preci;
	int					len;
}						t_tags;

typedef struct			s_env
{
	t_tags				tags;
	int					i;
	int					value;
	va_list				ap;
}						t_env;

typedef struct			s_nbr
{
	long long			val;
	unsigned long long	u_val;
	int					size;
	int					sign;
	char				c_sign;
	int					size_aff;
}						t_nbr;

int						ft_printf(const char *s, ...);
t_tags					find_tags(t_env *e, const char *s);
int						ft_printf_atoi(t_env *e, const char *str);
int						find_specifier(t_env *e, const char *s);
int						ft_strlen(char *str);
void					ft_putnbr_base(long long nb, char *b, long long s_b,
							t_env *e);
t_nbr					find_nbr_stats(t_nbr *nb, long long s_base, t_env *e);
void					ft_putunbr_base(unsigned long long nb, char *b,
							unsigned long long s_b, t_env *e);
t_nbr					find_unbr_stats(t_nbr *nb, unsigned long long s_b,
							t_env *e);
int						print_char(t_env *e);
int						print_str(t_env *e);
int						print_percent(t_env *e);
int						print_int(t_env *e);
int						print_uint(t_env *e, char specif);
int						print_ptr(t_env *e);

#endif
