/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:49 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:05:00 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_help_func(void)
{
	ft_putstr("command: ft_ssl [ALGORITHM] [OPTIONS] [FILES]\n\n");
	ft_putstr("ALGORITHMS:\n\tmd5\n\tsha256\n\tsha512\n\twhirlpool\n\n");
	ft_putstr("OPTIONS:\n \
\t-h: help\n \
\t-p: echo STDIN to STDOUT and append the checksum to STDOUT\n \
\t-q: quiet mode\n \
\t-c: capital letters\n \
\t-o: output file\n \
\t-n: only output hashes \
\t-r: reverse the format of the output.\n \
\t-s: print the sum of the given string\n");
}

int			set_flags(char **argv, t_data *data)
{
	int	flags;
	int	ns;
	int	i;

	flags = 0;
	ns = 0;
	i = ((argv[1][0] == '-') ? 1 : 2);
	while (argv[i] && argv[i][0] == '-')
	{
		while (argv[i][ns] == '-')
			ns++;
		if (!argv[i][ns] || argv[i][ns] == 'h')
		{
			print_help_func();
			return (0);
		}
		flags |= (1 << (argv[i++][ns] - 'a'));
		if (argv[i - 1][ns] == 'o')
			data->output_file = argv[i++];
	}
	if (!flags && !(argv[i]))
		flags |= (1 << ('p' - 'a'));
	check_flag(flags);
	return (i);
}

char		check_flag(int to_check)
{
	static int flags = -1;

	if (flags < 0)
	{
		flags = to_check;
		return (0);
	}
	if (flags & (1 << (to_check - 'a')))
		return (1);
	return (0);
}
