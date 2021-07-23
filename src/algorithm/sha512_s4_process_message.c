/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_s4_process_message.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:33 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:12:59 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha512.h"

static void	generate_w(int i, t_wrap msg, unsigned long w[80])
{
	int		j;
	unsigned long	s0;
	unsigned long	s1;
	t_wrap	p;

	p.l = (msg.l + i * 16);
	j = -1;
	while (++j < 16)
	{
		w[j] = ((unsigned long *)little_to_big(p.l, 1, sizeof(p.l)))[0];
		p.l += 1;
	}
	while (j < 80)
	{
		s0 = (w[j - 15] >> 1) | (w[j - 15] << (64 - 1));
		s0 ^= (w[j - 15] >> 8) | (w[j - 15] << (64 - 8));
		s0 ^= (w[j - 15] >> 7);
		s1 = (w[j - 2] >> 19) | (w[j - 2] << (64 - 19));
		s1 ^= (w[j - 2] >> 61) | (w[j - 2] << (64 - 61));
		s1 ^= (w[j - 2] >> 6);
		w[j] = w[j - 16] + s0 + w[j - 7] + s1;
		j++;
	}
}

static void	set_abcd(unsigned long *abcd, unsigned long ch, unsigned long maj)
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

static void	execute_operations(int i, unsigned long *abcd, unsigned long w[64])
{
	unsigned long ch;
	unsigned long maj;

	ch = (abcd[4] >> 14) | (abcd[4] << (64 - 14));
	ch ^= (abcd[4] >> 18) | (abcd[4] << (64 - 18));
	ch ^= (abcd[4] >> 41) | (abcd[4] << (64 - 41));
	ch += (abcd[4] & abcd[5]) ^ ((~abcd[4]) & abcd[6]);
	ch += abcd[7] + g_k512[i] + w[i];
	maj = (abcd[0] >> 28) | (abcd[0] << (64 - 28));
	maj ^= (abcd[0] >> 34) | (abcd[0] << (64 - 34));
	maj ^= (abcd[0] >> 39) | (abcd[0] << (64 - 39));
	maj += (abcd[0] & abcd[1]) ^ (abcd[0] & abcd[2]) ^ (abcd[1] & abcd[2]);
	set_abcd(abcd, ch, maj);
}

t_wrap		sha512_process_message(t_wrap msg, size_t msg_bits, t_wrap abcd)
{
	size_t	i;
	int		j;
	unsigned long	w[80];
	unsigned long	tmp_abcd[8];

	i = 0;
	while (i < msg_bits / 1024)
	{
		j = 0;
		generate_w(i++, msg, w);
		ft_memcpy(tmp_abcd, abcd.l, sizeof(unsigned long) * 8);
		j = 0;
		while (j < 80)
			execute_operations(j++, abcd.l, w);
		j = 0;
		while (j < 8)
		{
			abcd.l[j] += tmp_abcd[j];
			j++;
		}
	}
	return (abcd);
}
