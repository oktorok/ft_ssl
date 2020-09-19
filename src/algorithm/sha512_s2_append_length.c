#include "ft_ssl.h"

/*
** It should be added the case when size_t has 128
** bits but norminette doesnt let me because the
** werror flag
*/

t_wrap	sha512_append_length(t_wrap msg, size_t msg_bits, size_t orig_len)
{
	size_t	len_place;
	ulong	low;
	ulong	high;

	len_place = orig_len << 3;
	low = *((ulong *)little_to_big(&len_place, 1, 8));
	len_place = orig_len >> 61;
	high = *((ulong *)little_to_big(&len_place, 1, 8));
	high = to_big(orig_len >> 61);
	len_place = (msg_bits / 8) / 8;
	msg.l[len_place - 2] = high;
	msg.l[len_place - 1] = low;
	return (msg);
}
