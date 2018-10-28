#include "libft.h"

int			ft_count_words(char const *s, char c)
{
	int			i;
	int			words;

	words = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}
