/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 20:18:35 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_wrap	hashing(t_wrap digest, int hash)
{
	t_wrap	output;

	output.i = 0;
	if (hash == MD5)
		output = md5(digest);
	else if (hash == SHA256)
		output = sha256(digest);
	else if (hash == SHA512)
		output = sha512(digest);
	else if (hash == WHIRLPOOL)
		output = whirlpool(digest);
	return (output);
}

static void	print_error(t_source src, int hash)
{
	ft_putstr("ft_ssl: ");
	if (hash == MD5)
		ft_putstr("md5: ");
	else if (hash == SHA256)
		ft_putstr("sha256: ");
	else if (hash == SHA512)
		ft_putstr("sha512: ");
	else if (hash == WHIRLPOOL)
		ft_putstr("whirlpool: ");
	ft_putstr(src.name);
	ft_putendl(": No such file or directory");
}

static t_data	*check_input(int argn, char **argv)
{
	t_data	*data;

	if (argn < 2)
	{
		ft_putendl("ft_ssl: Incorrect format, write -h or --help for \
an explanation of the correct format");
		return (NULL);
	}
	data = init(argv, argn);
	return (data);
}

int	main(int argn, char **argv)
{
	t_data	*data;
	int		j;
	t_wrap	digest;
	t_wrap	output;

	data = check_input(argn, argv);
	if (!data)
		return (-1);
	j = data->source_num - 1;
	while (j >= 0)
	{
		digest.c = data->srcs[j].src;
		if (digest.c)
		{
			output = hashing(digest, data->hash);
			if (!output.c)
				return (-1);
			print_hex(output.uc, data->srcs[j--], data);
		}
		else
			print_error(data->srcs[j--], data->hash);
	}
	if (data->output_fd)
		close(data->output_fd);
	return (1);
}
