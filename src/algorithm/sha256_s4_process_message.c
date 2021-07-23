/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_s4_process_message.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:33 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:12:26 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"

static void	generate_w(int i, t_wrap msg, unsigned int w[64])
{
	int				j;
	unsigned int	s0;
	unsigned int	s1;
	t_wrap			p;

	p.i = (msg.i + i * 16);
	j = -1;
	while (++j < 16)
	{
		w[j] = ((unsigned int *)little_to_big(p.i, 1, sizeof(p.i[0])))[0];
		w[j] = *p.i;
		p.i += 1;
	}
	while (j < 64)
	{
		s0 = (w[j - 15] >> 7) | (w[j - 15] << (32 - 7));
		s0 ^= (w[j - 15] >> 18) | (w[j - 15] << (32 - 18));
		s0 ^= (w[j - 15] >> 3);
		s1 = (w[j - 2] >> 17) | (w[j - 2] << (32 - 17));
		s1 ^= (w[j - 2] >> 19) | (w[j - 2] << (32 - 19));
		s1 ^= (w[j - 2] >> 10);
		w[j] = w[j - 16] + s0 + w[j - 7] + s1;
		j++;
	}
}

static void	set_abcd(unsigned int *abcd, unsigned int ch, unsigned int maj)
{
	abcd[7] = abcd[6];
	abcd[6] = abcd[5];
	abcd[5] = abcd[4];
	abcd[4] = abcd[3] + ch;
	abcd[3] = abcd[2];
	abcd[2] = abcd[1];
	abcd[1] = abcd[0];
	abcd[0] = ch + maj;
}

static void	execute_operations(int i, unsigned int *abcd, unsigned int w[64])
{
	unsigned int	ch;
	unsigned int	maj;

	ch = (abcd[4] >> 6) | (abcd[4] << (32 - 6));
	ch ^= (abcd[4] >> 11) | (abcd[4] << (32 - 11));
	ch ^= (abcd[4] >> 25) | (abcd[4] << (32 - 25));
	ch += (abcd[4] & abcd[5]) ^ ((~abcd[4]) & abcd[6]);
	ch += abcd[7] + g_k[i] + w[i];
	maj = (abcd[0] >> 2) | (abcd[0] << (32 - 2));
	maj ^= (abcd[0] >> 13) | (abcd[0] << (32 - 13));
	maj ^= (abcd[0] >> 22) | (abcd[0] << (32 - 22));
	maj += (abcd[0] & abcd[1]) ^ (abcd[0] & abcd[2]) ^ (abcd[1] & abcd[2]);
	set_abcd(abcd, ch, maj);
}

t_wrap	sha256_process_message(t_wrap msg, size_t msg_bits, t_wrap abcd)
{
	size_t			i;
	int				j;
	unsigned int	w[64];
	unsigned int	tmp_abcd[8];

	i = 0;
	while (i < msg_bits / (32 * 16))
	{
		j = 0;
		generate_w(i++, msg, w);
		ft_memcpy(tmp_abcd, abcd.i, sizeof(unsigned int) * 8);
		j = 0;
		while (j < 64)
			execute_operations(j++, abcd.i, w);
		j = 0;
		while (j < 8)
		{
			abcd.i[j] += tmp_abcd[j];
			j++;
		}
	}
	return (abcd);
}
