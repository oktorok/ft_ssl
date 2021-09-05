/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_s2_append_length.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:33 by jagarcia          #+#    #+#             */
/*   Updated: 2021/09/06 00:12:57 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_wrap	md5_append_length(t_wrap msg, size_t msg_bits, size_t orig_len)
{
	size_t	len_place;

	orig_len *= 8;
	len_place = msg_bits / 8 - 8;
	msg.l[len_place / 8] = orig_len;
	return (msg);
}
