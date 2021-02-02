/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool_s4_process_message.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:33 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:11:25 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "whirlpool.h"

static void	sb_sc(unsigned char *cstate)
{
	int		i;
	int		row_mod;
	int		column;
	char	output[64];

	i = 0;
	while (i < 64)
	{
		row_mod = (cstate[i] >> 4);
		column = (cstate[i] & 0x0F);
		cstate[i++] = g_s[16 * row_mod + column];
	}
	i = 0;
	while (i < 64)
	{
		row_mod = ((i / 8) - (i % 8)) % 8;
		if (row_mod < 0)
			row_mod = row_mod + 8;
		row_mod = 8 * row_mod + (i % 8);
		output[i] = cstate[row_mod];
		i += 1;
	}
	i = -1;
	while (++i < 64)
		cstate[i] = output[i];
}

static void	mr(unsigned char *cstate)
{
	int				i;
	unsigned char	output[64];

	i = -1;
	while (++i < 64)
	{
		output[i] = gf_mult(cstate[8 * (i / 8)], g_c[i % 8])
			^ gf_mult(cstate[8 * (i / 8) + 1], g_c[8 * 1 + i % 8])
			^ gf_mult(cstate[8 * (i / 8) + 2], g_c[8 * 2 + i % 8])
			^ gf_mult(cstate[8 * (i / 8) + 3], g_c[8 * 3 + i % 8])
			^ gf_mult(cstate[8 * (i / 8) + 4], g_c[8 * 4 + i % 8])
			^ gf_mult(cstate[8 * (i / 8) + 5], g_c[8 * 5 + i % 8])
			^ gf_mult(cstate[8 * (i / 8) + 6], g_c[8 * 6 + i % 8])
			^ gf_mult(cstate[8 * (i / 8) + 7], g_c[8 * 7 + i % 8]);
	}
	i = -1;
	while (++i < 64)
		cstate[i] = output[i];
}

static void	ak(unsigned char *cstate, unsigned char *k)
{
	int		i;

	i = -1;
	while (++i < 64)
		cstate[i] = cstate[i] ^ k[i];
}

static void	rf(unsigned char *k, int round)
{
	unsigned char	rc[64];
	int				i;

	i = 0;
	while (i < 64)
	{
		if (i < 8)
			rc[i] = g_s[8 * (round - 1) + i];
		else
			rc[i] = 0;
		i++;
	}
	sb_sc(k);
	mr(k);
	ak(k, rc);
}

t_wrap		whirlpool_process_message(t_wrap cstate, size_t msg_bits, t_wrap h)
{
	int				i;
	size_t			block;
	unsigned char	k[64];

	block = -1;
	while (++block * 512 < msg_bits)
	{
		i = -1;
		ft_memcpy(k, h.uc, 64);
		while (++i < 64)
			h.uc[i] ^= cstate.uc[block * 64 + i];
		ak(cstate.uc + (block * 64), k);
		while (i++ < 74)
		{
			sb_sc(cstate.uc + (block * 64));
			mr(cstate.uc + (block * 64));
			rf(k, i - 64);
			ak(cstate.uc + (block * 64), k);
		}
		i = -1;
		while (++i < 64)
			h.uc[i] ^= cstate.uc[block * 64 + i];
	}
	return (h);
}
