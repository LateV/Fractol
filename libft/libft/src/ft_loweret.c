#include "libft.h"

char	ft_loweret(char a)
{
	char r;

	if (a >= 'A' && a <= 'Z')
	{
		r = a + 32;
		return (r);
	}
	return (a);
}
