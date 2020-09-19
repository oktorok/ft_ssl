#include "ft_ssl.h"

t_wrap	sha512_append_bits(t_wrap msg, size_t msg_bits)
{
	msg.uc[msg_bits] |= (1 << 7);
	return (msg);
}
