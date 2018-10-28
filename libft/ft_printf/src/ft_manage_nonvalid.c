#include "../inc/ft_printf.h"

int		ft_manage_nonvalid(t_format *p, char str)
{
	int	ret;

	ret = 0;
	ft_parse_width(p, 1);
	if (p->flag_minus == 0 && p->flag_zero == 0 && p->width > 0)
		while (p->width-- > 0)
		{
			ft_putchar(' ');
			ret += 1;
		}
	if (p->flag_minus > 0 || p->flag_zero > 0)
	{
		if (p->flag_minus > 0)
			ft_putwchar(str);
		ft_print_space_zero(p, &ret);
	}
	if (p->flag_minus < 1)
		ft_putwchar(str);
	return (ret + 1);
}
