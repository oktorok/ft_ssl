/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2021/08/29 22:08:31 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_wrap	md5(t_wrap msg, size_t length)
{
	size_t		original_length;
	size_t		msg_bits;
	t_wrap		digest;
	t_wrap		final;

	original_length = length;
	msg_bits = original_length * 8 + calc_adding_bits(original_length * 8) + 64;
	digest.c = ft_memalloc(msg_bits / 8);
	digest.c = ft_memcpy(digest.c, msg.c, original_length);
	if (!digest.c)
		return (digest);
	digest = md5_append_bits(digest, original_length);
	digest = md5_append_length(digest, msg_bits, original_length);
	final = md5_create_buffer();
	if (!final.c)
		return (final);
	final = md5_process_message(digest, msg_bits, final);
	ft_strdel(&digest.c);
	return (final);
}
