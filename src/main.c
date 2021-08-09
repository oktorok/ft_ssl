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
#include "extern.h"

static t_wrap	hashing(t_wrap digest, int hash, size_t length)
{
	t_wrap	output;

	output.i = 0;
	output = g_algo_func[hash](digest, length);
	return (output);
}

static void	print_error(t_source src, int hash)
{
	const char	*hash_str;

	ft_putstr("ft_ssl: ");
	hash_str = g_algo_str[hash];
	ft_putstr(hash_str);
	ft_putstr(": ");
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

static void	finish_program(t_data *data, t_wrap output)
{
	int i;

	i = 0;
	if (data->output_fd)
		close(data->output_fd);
	while (i < data->source_num)
	{
		if (data->srcs[i].type == FILE || data->srcs[i].type == STRING)
			free(data->srcs[i].src);
		i++;
	}
	free(data->srcs);
	free(data);
	free(output.c);
}

int	main(int argn, char **argv)
{
	t_data	*data;
	int		j;
	t_wrap	digest;
	t_wrap	output;

	data = check_input(argn, argv);
	if (!data)
		return (0);
	j = data->source_num - 1;
	while (j >= 0)
	{
		digest.c = data->srcs[j].src;
		if (digest.c)
		{
			output = hashing(digest, data->hash, data->srcs[j].size);
			if (!output.c)
				return (0);
			print_hex(output.uc, data->srcs[j--], data);
		}
		else
			print_error(data->srcs[j--], data->hash);
	}
	finish_program(data, output);
	return (1);
}
