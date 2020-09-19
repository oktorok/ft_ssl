#include "ft_ssl.h"

static int	bits_for_add(size_t msg_bits)
{
	int	mod_1024;

	if (msg_bits && !(msg_bits % 896))
		return (1024);
	mod_1024 = msg_bits % 1024;
	if (mod_1024 > 896)
		return (896 + (1024 - mod_1024));
	return (896 - mod_1024);
}

t_wrap	sha512(t_wrap msg)
{
	size_t		original_length;
	size_t		msg_bits;
	t_wrap		digest;
	t_wrap		final;

	original_length = ultra_strlen(msg.c);
	msg_bits = original_length * 8 + bits_for_add(original_length * 8) + 128;
	if (!(digest.c = ft_strrealloc(msg.c, msg_bits / 8)))
		return (digest);
	digest = sha512_append_bits(digest, original_length);
	digest = sha512_append_length(digest, msg_bits, original_length);
	final = sha512_create_buffer();
	if (!final.c)
		return (final);
	final = sha512_process_message(digest, msg_bits, final);
	final.l = (ulong *)little_to_big(final.l, 8, sizeof(final.l[0]));
	ft_strdel(&digest.c);
	return (final);
}
