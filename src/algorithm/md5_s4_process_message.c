#include "ft_ssl.h"
#include "md5.h"

static uint	functions(uint x, uint y, uint z, char func)
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

static uint	*generate_x(int i, uint *msg, uint x[64])
{
	ft_memcpy(x, msg + i * 16, 16 * sizeof(uint));
	return (x);
}

static void execute_operations(uint *abcd, uint *x, const char* op)
{
	uint	values[3];
	short	j[4];
	uint	tmp;
	j[0] = op[0] - 'A';
	j[1] = op[1] - 'A';
	j[2] = op[2] - 'A';
	j[3] = op[3] - 'A';
	values[0] = ft_atoi(op + 7);
	values[1] = ft_atoi(op + 10);
	values[2] = ft_atoi(op + 13);
	tmp = (abcd[j[0]] + functions(abcd[j[1]], abcd[j[2]], abcd[j[3]], op[5]) + x[values[0]] + t[values[2] - 1]);
	abcd[j[0]] = abcd[j[1]] + ((tmp << values[1]) | (tmp >> (32 - values[1])));
}

t_wrap	md5_process_message(t_wrap msg, size_t msg_bits, t_wrap abcd)
{
	size_t		i;
	int			j;
	uint		x[16];
	uint		tmp_abcd[4];
	

	i = 0;
	while (i < msg_bits / (32 * 16))
	{
		j = 0;
		generate_x(i++, msg.i, x);
		ft_memcpy(tmp_abcd, abcd.l, sizeof(ulong) * 2);
		while (j < 64)
			execute_operations(abcd.i, x, operations[j++]);
		abcd.i[0] += tmp_abcd[0];
		abcd.i[1] += tmp_abcd[1];
		abcd.i[2] += tmp_abcd[2];
		abcd.i[3] += tmp_abcd[3];
	}
	return (abcd);
}
