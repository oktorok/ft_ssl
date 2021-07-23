/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_s3_create_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:33 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:06:23 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_wrap	md5_create_buffer(void)
{
	t_wrap	buffer;

	if (!(buffer.i = (unsigned int *)ft_memalloc(sizeof(unsigned int) * 4)))
		return (buffer);
	buffer.i[0] = 0x67452301;
	buffer.i[1] = 0xefcdab89;
	buffer.i[2] = 0x98badcfe;
	buffer.i[3] = 0x10325476;
	return (buffer);
}
