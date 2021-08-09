/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:06:36 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	digest.c = ft_strrealloc(&msg.c, msg_bits / 8);
	if (!digest.c)
		return (digest);
	digest = sha512_append_bits(digest, original_length);
	digest = sha512_append_length(digest, msg_bits, original_length);
	final = sha512_create_buffer();
	if (!final.c)
		return (final);
	final = sha512_process_message(digest, msg_bits, final);
	final.l = (unsigned long *)little_to_big(final.l, 8, sizeof(final.l[0]));
	ft_strdel(&digest.c);
	return (final);
}
