#include "ft_ssl.h"

void	*little_to_big(void *vsrc, size_t size, size_t offset)
{
	size_t	i;
	size_t	j;
	char	tmp[MAX_OFFSET];
	char	*src;

	src = (char *)vsrc;
	i = 0;
	while (i < size * offset)
	{
		j = 0;
		while (j < offset)
		{
			tmp[j] = src[i + offset - j - 1];
			j++;
		}
		ft_memcpy(src + i, tmp, offset);
		i += offset;
	}
	return (vsrc);
}
