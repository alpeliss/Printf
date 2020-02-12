/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpeliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:18:38 by alpeliss          #+#    #+#             */
/*   Updated: 2020/02/12 18:59:45 by alpeliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "stdio.h"
#include "limits.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>
#include <float.h>
#include <termios.h>

void global_test(void)
{	
	int	i;
	int	j;
	printf("%d VS %d\n\n"
			,printf("Un test\n")
			,ft_printf("Un test\n")
			);

	printf("%d VS %d\n\n"
			,printf("")
			,ft_printf("")
			);

	ft_printf(NULL);
}
/*
void char_test(char c)
{
	printf("%d VS %d\n\n"
			,printf("-%c-\n", c)
			,ft_printf("-%c-\n", c)
			);
	printf("%d VS %d\n\n"
			,printf("-%15c-\n", c)
			,ft_printf("-%15c-\n", c)
			);
	printf("%d VS %d\n\n"
			,printf("-%-15c-\n", c)
			,ft_printf("-%-15c-\n", c)
			);
	printf("%d VS %d\n\n"
			,printf("-%015c-\n", c)
			,ft_printf("-%015c-\n", c)
			);
	printf("%d VS %d\n\n"
			,printf("-%-015c-\n", c)
			,ft_printf("-%-015c-\n", c)
			);

	printf("%d VS %d\n\n"
			,printf("-%*c-\n", 10, c)
			,ft_printf("-%*c-\n", 10, c)
			);
	printf("%d VS %d\n\n"
			,printf("-%.15c-\n", c)
			,ft_printf("-%.15c-\n", c)
			);
	printf("%d VS %d\n\n"
			,printf("-%.*c-\n", 10, c)
			,ft_printf("-%.*c-\n", 10, c)
			);
	printf("%d VS %d\n\n"
			,printf("-%-0*c-\n", 10, c)
			,ft_printf("-%-0*c-\n", 10, c)
			);
}
*/
int main()
{
	char *t;

	t= "iowhioewhioefhiowhfio";
//	printf("---------- global test-----------\n\n");
//	global_test();
//	printf("----------  char test  ----------\n\n");
//	char_test('*');
//	printf("^.^/%-42c^.^/", (char)10);
//	printf("\n\n------------\n\n");
//	ft_printf("^.^/%-42c^.^/", (char)10);
	printf("{%*3d}", 5, 0);
	printf("\n");
	ft_printf("{%*3d}", 5, 0);
}
