#include "../inc/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	argptr;
	char	*str;
	char	*p;

	ret = 0;
	va_start(argptr, format);
	str = ft_strdup(format);
	p = str;
	while (*str)
	{
		if (*str == '%')
			str += ft_notion(&argptr, &str, &ret);
		else
		{
			write(1, str, 1);
			ret++;
		}
		(*str) ? str += 1 : 0;
	}
	free(p);
	va_end(argptr);
	return (ret);
}
