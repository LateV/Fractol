#include "libft.h"

size_t		ft_len_num(intmax_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
