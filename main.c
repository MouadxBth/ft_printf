#include <stdio.h>
#include "ft_printf.h"

int     main(void)
{
	unsigned long a = 4294967295;
	//printf("%lu\n", ft_nbrlen(140729151582108, 0, 16));
        printf("%i\n", ft_printf(" %lu ", -1 * a));
        printf("%i\n", printf(" %lu ", -1 * a));
        //printf("%lu\n", ft_nbrlen(a, 0, 16));
	return (0);
}
