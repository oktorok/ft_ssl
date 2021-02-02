/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:49 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 19:59:15 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_prolog(int hash, t_source src, int fd)
{
	if (src.type == INPUT && check_flag('p'))
	{
		if (src.src[ft_strlen(src.src) - 1] != '\n')
			ft_putendl_fd(src.src, fd);
		return ;
	}
	if (check_flag('r') || check_flag('q'))
		return ;
	if (hash == MD5)
		ft_putstr_fd("MD5 (", fd);
	else if (hash == SHA256)
		ft_putstr_fd("SHA256 (", fd);
	else if (hash == SHA512)
		ft_putstr_fd("SHA512 (", fd);
	else if (hash == WHIRLPOOL)
		ft_putstr_fd("WHIRLPOOL (", fd);
	if (src.type == STRING)
	{
		ft_putchar_fd('\"', fd);
		ft_putstr_fd(src.name, fd);
		ft_putchar_fd('\"', fd);
	}
	else if (src.type == FILE)
		ft_putstr_fd(src.name, fd);
	ft_putstr_fd(") = ", fd);
}

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
	int length;

	if (hash == MD5)
		length = 16;
	else if (hash == SHA256)
		length = 32;
	else if (hash == SHA512 || hash == WHIRLPOOL)
		length = 64;
	return (length);
}

static void	write_hash(u_char byte, int fd)
{
	char	*t;

	t = ft_itoa_base(byte, 16);
	if (!check_flag('c'))
		t = ft_strmap(t, ft_tolower);
	if (ft_strlen(t) != 2)
		ft_putchar_fd('0', fd);
	ft_putstr_fd(t, fd);
	ft_strdel(&t);
}

void		print_hex(u_char *output, t_source src, int hash, char *output_file)
{
	int		fd;
	int		j;
	int		length;

	j = 0;
	fd = 1;
	length = set_length(hash);
	if (output_file)
		fd = open(output_file, O_WRONLY | O_CREAT, 0666);
	if (!check_flag('n'))
		print_prolog(hash, src, fd);
	while (j < length)
		write_hash(output[j++], fd);
	if (!check_flag('q') && !check_flag('n'))
		print_epilog(src, fd);
	ft_putendl_fd("", fd);
	if (fd)
		close(fd);
}
