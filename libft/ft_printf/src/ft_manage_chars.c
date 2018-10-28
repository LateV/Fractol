#include "../inc/ft_printf.h"

static	void	parse_flags(wint_t arg, t_format *p, int len_arg, int *ret)
{
	p->width = p->width - len_arg;
	if (p->flag_minus == 0 && p->flag_zero == 0 && p->width > 0)
		while (p->width-- > 0)
		{
			ft_putchar(' ');
			*ret += 1;
		}
	if (p->flag_minus > 0 || p->flag_zero > 0)
	{
		if (p->flag_minus > 0)
			p->length_l > 0 ? *ret += ft_putwchar(arg) : ft_putchar(arg);
		ft_print_space_zero(p, ret);
	}
	if (p->flag_minus < 1)
		p->length_l > 0 ? *ret += ft_putwchar(arg) : ft_putchar(arg);
}

int				ft_manage_chars(va_list *argptr, t_format *p)
{
	wint_t		arg;
	int			ret;

	ret = 1;
	p->length_l > 0 ? ret = 0 : 0;
	if (p->type == '%')
		arg = '%';
	else
		arg = ft_parse_chars_length(p, argptr);
	parse_flags(arg, p, 1, &ret);
	return (ret);
}
