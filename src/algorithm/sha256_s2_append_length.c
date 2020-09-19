#include "ft_ssl.h"

t_wrap	sha256_append_length(t_wrap msg, size_t msg_bits, size_t orig_len)
{
	size_t		len_place;

	orig_len *= 8;
	len_place = msg_bits / 8 - 8;
	msg.uc[len_place + 7] = orig_len;
	msg.uc[len_place + 6] = orig_len >> 8;
	msg.uc[len_place + 5] = orig_len >> 16;
	msg.uc[len_place + 4] = orig_len >> 24;
	msg.uc[len_place + 3] = orig_len >> 32;
	msg.uc[len_place + 2] = orig_len >> 40;
	msg.uc[len_place + 1] = orig_len >> 48;
	msg.uc[len_place] = orig_len >> 56;
	return (msg);
}
