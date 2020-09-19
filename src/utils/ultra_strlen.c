#include "ft_ssl.h"

size_t	ultra_strlen(char *src)
{
	size_t size;

	size = 0;
	if (!src)
		return (0);
	while (*src && size != 0xFFFFFFFFFFFFFFFF)
	{
		src++;
		size++;
	}
	return (size);
}
