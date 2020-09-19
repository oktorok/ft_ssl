#include "ft_ssl.h"

int	calc_adding_bits(size_t msg_bits)
{
	int	mod_512;

	if (msg_bits && !(msg_bits % 448))
		return (512);
	mod_512 = msg_bits % 512;
	if (mod_512 > 448)
		return (448 + (512 - mod_512));
	return (448 - mod_512);
}
