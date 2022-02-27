#include <stdio.h>
#include "ft_printf.h"

int     main(void)
{
	int a = 612937244;
	//printf("%lu\n", ft_nbrlen(140729151582108, 0, 16));
        ft_printf("ft -> %i\n", ft_printf("%p\n", &a));
        printf("-> %i\n", printf("%p\n", &a));
        return (0);
}
