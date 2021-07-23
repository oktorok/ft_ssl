/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:08:58 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_wrap	sha256(t_wrap msg)
{
	size_t		original_length;
	size_t		msg_bits;
	t_wrap		digest;
	t_wrap		final;

	original_length = ultra_strlen(msg.c);
	msg_bits = original_length * 8 + calc_adding_bits(original_length * 8) + 64;
	digest.c = ft_strrealloc(msg.c, msg_bits / 8);
	if (!digest.c)
		return (digest);
	digest = sha256_append_bits(digest, original_length);
	digest = sha256_append_length(digest, msg_bits, original_length);
	final = sha256_create_buffer();
	if (!final.c)
		return (final);
	final = sha256_process_message(digest, msg_bits, final);
	final.i = (unsigned int *)little_to_big(final.i, 8, sizeof(final.i[0]));
	ft_strdel(&digest.c);
	return (final);
}
