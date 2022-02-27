#include <stdio.h>
#include "ft_printf.h"

int     main(void)
{
	int a = 666;

	//printf("%lu\n", ft_nbrlen(140729151582108, 0, 16));
        ft_printf("%-5c%c", 'X', 'b');
        //printf("%lu\n", ft_nbrlen(a, 0, 16));
	return (0);
}
