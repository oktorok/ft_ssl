/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gf_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:49 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:04:52 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned char		gf_mult(unsigned char a, unsigned char b)
{
	unsigned char	p;
	int				i;
	int				carry;

	p = 0;
	i = 0;
	while (a && b)
	{
		if (b & 0x1)
			p ^= a;
		b = (b >> 1);
		carry = (a & 0x80);
		a = (a << 1);
		if (carry)
			a ^= 0x1d;
		i++;
	}
	return (p);
}
