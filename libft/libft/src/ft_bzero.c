#include "libft.h"

void	*ft_bzero(void *b, size_t n)
{
	unsigned char	*i;
	size_t			j;

	i = (unsigned char *)b;
	j = 0;
	while (j < n)
	{
		i[j] = 0;
		j++;
	}
	return (b);
}
