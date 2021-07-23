/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_s3_create_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:33 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:06:01 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_wrap	sha256_create_buffer(void)
{
	t_wrap	buffer;

	if (!(buffer.i = (unsigned int *)ft_memalloc(sizeof(unsigned int) * 8)))
		return (buffer);
	buffer.i[0] = 0x6a09e667;
	buffer.i[1] = 0xbb67ae85;
	buffer.i[2] = 0x3c6ef372;
	buffer.i[3] = 0xa54ff53a;
	buffer.i[4] = 0x510e527f;
	buffer.i[5] = 0x9b05688c;
	buffer.i[6] = 0x1f83d9ab;
	buffer.i[7] = 0x5be0cd19;
	return (buffer);
}
