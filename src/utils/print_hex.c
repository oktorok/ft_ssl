/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:49 by jagarcia          #+#    #+#             */
/*   Updated: 2021/08/29 03:13:47 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_epilog(t_source src, int fd)
{
	if (check_flag('r') && src.type != INPUT)
	{
		ft_putchar_fd(' ', fd);
		if (src.type == STRING)
		{
			ft_putchar_fd('\"', fd);
			ft_putstr_fd(src.name, fd);
			ft_putchar_fd('\"', fd);
		}
		else if (src.type == FILE)
			ft_putstr_fd(src.name, fd);
	}
}

static int	set_length(int hash)
{
	int	length;

	length = g_algo_num[hash];
	return (length);
}

static void	write_hash(unsigned char byte, int fd)
{
	char	*t;
	char	*tt;

	tt = ft_itoa_base(byte, 16);
	if (!check_flag('c'))
	{
		t = ft_strmap(tt, ft_tolower);
		ft_strdel(&tt);
	}
	else
		t = tt;
	if (ft_strlen(t) != 2)
		ft_putchar_fd('0', fd);
	ft_putstr_fd(t, fd);
	ft_strdel(&t);
}

void	print_hex(unsigned char *output, t_source src, t_data *data)
{
	int		fd;
	int		j;
	int		length;

	j = 0;
	fd = 1;
	length = set_length(data->hash);
	if (data->output_fd)
		fd = data->output_fd;
	if (!check_flag('n') && (!check_flag('q') || data->source_num > 1))
		print_prolog(data, src, fd);
	while (j < length)
		write_hash(output[j++], fd);
	if (!check_flag('q') && !check_flag('n'))
		print_epilog(src, fd);
	ft_putendl_fd("", fd);
	free(output);
}
