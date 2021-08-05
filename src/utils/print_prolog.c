/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prolog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:49 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 19:59:15 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	input_type(t_data *data, t_source src, int fd)
{
	if (check_flag('p'))
	{
		if (src.src[ft_strlen(src.src) - 1] != '\n')
			ft_putstr_fd(src.src, fd);
		else if (data->source_num == 1)
		{
			write(fd, src.src, ft_strlen(src.src) - 1);
			ft_putstr_fd("= ", fd);
		}
		else
			ft_putstr_fd(src.src, fd);
	}
	else
		ft_putstr_fd("(stdin)= ", fd);
}

void	print_prolog(t_data *data, t_source src, int fd)
{
	const char	*hash_str;

	if (src.type == INPUT)
	{
		input_type(data, src, fd);
		return ;
	}
	if (check_flag('r') || check_flag('q'))
		return ;
	hash_str = g_algo_str[data->hash];
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
}
