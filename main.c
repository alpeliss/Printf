/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:38 by alpeliss          #+#    #+#             */
/*   Updated: 2020/01/27 20:38:00 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "stdio.h"

int main()
{
/*	printf("%d VS %d\n\n"
			,printf("Un test\n")
			,ft_printf("Un test\n")
			);

	printf("%d VS %d\n\n"
			,printf("")
			,ft_printf("")
			);

	printf("%d VS %d\n"
			,printf(NULL)
			,ft_printf(NULL)
			);

	printf("%d VS %d\n\n"
			,printf("%%")
			,ft_printf("%%")
			);
	printf("%d VS %d\n\n"
			,printf("")
			,ft_printf("")
			);
	printf("%d VS %d\n\n"
			,printf("")
			,ft_printf("")
			);
	printf("%0.45d", 45);*/
	ft_printf("%000-0*.*d", 45, 150);
	printf("%o\n", -1);
}
