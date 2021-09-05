/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prolog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:49 by jagarcia          #+#    #+#             */
/*   Updated: 2021/08/29 22:10:15 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	input_type(t_source src, int fd)
{
	int	q;

	q = check_flag('q');
	if (check_flag('p'))
	{
		if (!q)
			ft_putstr_fd("(\"", fd);
		if (src.size && src.src[src.size - 1] != '\n')
			ft_putstr_fd(src.src, fd);
		else if (src.size)
			write(fd, src.src, src.size - 1);
		if (!q)
			ft_putstr_fd("\")= ", fd);
		else
			ft_putstr_fd("\n", fd);
	}
	else
		ft_putstr_fd("(stdin)= ", fd);
}

static char	*str_toupper(char *hash)
{
	char	*begin;

	begin = hash;
	while (*hash)
	{
		*hash = ft_toupper(*hash);
		hash++;
	}
	return (begin);
}

void	print_prolog(t_data *data, t_source src, int fd)
{
	char	*hash_str;

	if (src.type == INPUT)
	{
		input_type(src, fd);
		return ;
	}
	if (check_flag('r'))
		return ;
	hash_str = str_toupper(g_algo_str[data->hash]);
	ft_putstr_fd(hash_str, fd);
	ft_putstr_fd(" (", fd);
	if (src.type == STRING)
	{
		ft_putchar_fd('\"', fd);
		ft_putstr_fd(src.name, fd);
		ft_putchar_fd('\"', fd);
	}
	else if (src.type == FILE)
		ft_putstr_fd(src.name, fd);
	ft_putstr_fd(") = ", fd);
	return ;
}
