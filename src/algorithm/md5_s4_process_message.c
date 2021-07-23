/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_s4_process_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:33 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:13:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"

static unsigned int	functions(unsigned int x, unsigned int y, unsigned int z, char func)
{
	if (func == 'F')
		return (x & y) | ((~x) & z);
	else if (func == 'G')
		return ((x & z) | (y & (~z)));
	else if (func == 'H')
		return (x ^ y ^ z);
	else if (func == 'I')
		return (y ^ (x | ~z));
	return (-1);
}

static unsigned int	*generate_x(int i, unsigned int *msg, unsigned int x[64])
{
	ft_memcpy(x, msg + i * 16, 16 * sizeof(unsigned int));
	return (x);
}

static void	execute_operations(unsigned int *abcd, unsigned int *x, const char *op)
{
	unsigned int	values[3];
	short	j[4];
	unsigned int	tmp;

	j[0] = op[0] - 'A';
	j[1] = op[1] - 'A';
	j[2] = op[2] - 'A';
	j[3] = op[3] - 'A';
	values[0] = ft_atoi(op + 7);
	values[1] = ft_atoi(op + 10);
	values[2] = ft_atoi(op + 13);
	tmp = (abcd[j[0]] + functions(abcd[j[1]], abcd[j[2]], abcd[j[3]], op[5])
			+ x[values[0]] + g_t[values[2] - 1]);
	abcd[j[0]] = abcd[j[1]] + ((tmp << values[1]) | (tmp >> (32 - values[1])));
}

t_wrap		md5_process_message(t_wrap msg, size_t msg_bits, t_wrap abcd)
{
	size_t		i;
	int			j;
	unsigned int		x[16];
	unsigned int		tmp_abcd[4];

	i = 0;
	while (i < msg_bits / (32 * 16))
	{
		j = 0;
		generate_x(i++, msg.i, x);
		ft_memcpy(tmp_abcd, abcd.l, sizeof(unsigned long) * 2);
		while (j < 64)
			execute_operations(abcd.i, x, g_operations[j++]);
		abcd.i[0] += tmp_abcd[0];
		abcd.i[1] += tmp_abcd[1];
		abcd.i[2] += tmp_abcd[2];
		abcd.i[3] += tmp_abcd[3];
	}
	return (abcd);
}
