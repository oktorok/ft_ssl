/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2021/09/06 00:11:48 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int calc_adding_bits_whirlpool(size_t msg_bits)
{
	int l;

	l = msg_bits/256;
	if (l % 2)
		return (256 - (msg_bits % 256) + 256);
	else
		return (256 - (msg_bits % 256));
}

t_wrap	whirlpool(t_wrap msg, size_t length)
{
	size_t		original_length;
	size_t		msg_bits;
	t_wrap		digest;
	t_wrap		final;

	original_length = length;
	msg_bits = original_length * 8 + calc_adding_bits_whirlpool(original_length * 8) + 256;
	digest.c = ft_memalloc(msg_bits / 8);
	digest.c = ft_memcpy(digest.c, msg.c, original_length);
	if (!digest.c)
		return (digest);
	digest = whirlpool_append_bits(digest, original_length);
	digest = whirlpool_append_length(digest, msg_bits, original_length);
	final = whirlpool_create_buffer();
	if (!final.c)
		return (final);
	final = whirlpool_process_message(digest, msg_bits, final);
	ft_strdel(&digest.c);
	return (final);
}
