/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:03:28 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_wrap	whirlpool(t_wrap msg)
{
	size_t		original_length;
	size_t		msg_bits;
	t_wrap		digest;
	t_wrap		final;

	original_length = ultra_strlen(msg.c);
	msg_bits = original_length * 8 + calc_adding_bits(original_length * 8) + 64;
	digest.c = ft_strrealloc(&msg.c, msg_bits / 8);
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
