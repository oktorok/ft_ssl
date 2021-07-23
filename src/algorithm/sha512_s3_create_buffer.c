/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_s3_create_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:33 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:05:37 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_wrap	sha512_create_buffer(void)
{
	t_wrap	buffer;

	if (!(buffer.l = (unsigned long *)ft_memalloc(sizeof(unsigned long) * 8)))
		return (buffer);
	buffer.l[0] = 0x6a09e667f3bcc908;
	buffer.l[1] = 0xbb67ae8584caa73b;
	buffer.l[2] = 0x3c6ef372fe94f82b;
	buffer.l[3] = 0xa54ff53a5f1d36f1;
	buffer.l[4] = 0x510e527fade682d1;
	buffer.l[5] = 0x9b05688c2b3e6c1f;
	buffer.l[6] = 0x1f83d9abfb41bd6b;
	buffer.l[7] = 0x5be0cd19137e2179;
	return (buffer);
}
