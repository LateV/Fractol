#include "../inc/ft_printf.h"

void	ft_parse_precision(t_format *p, int len_arg, int *ret)
{
	if (p->precision > 0)
		while (p->precision-- - len_arg > 0)
		{
			ft_putchar('0');
			*ret += 1;
		}
}
