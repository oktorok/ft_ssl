/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:06:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	set_src_params(t_source *srcs, char *name, int *j, int input)
{
	srcs[*j].name = name;
	srcs[*j].type = input;
	(*j)++;
}

static int	check_p_s(t_source *srcs, int *j, char **argv)
{
	char	*tmp_s;
	int		i;

	if (check_flag('s'))
		tmp_s = ft_strdup(*argv++);
	i = *j;
	while (argv[i])
		i++;
	i--;
	while (i + 1)
	{
		if (take_file(argv[i], &srcs[*j].src) < 0)
			return (0);
		set_src_params(srcs, argv[i--], j, FILE);
	}
	if (check_flag('s'))
	{
		srcs[*j].src = tmp_s;
		if (!srcs[*j].src)
			return (0);
		set_src_params(srcs, srcs[*j].src, j, STRING);
	}
	return (1);
}

static t_source	*fill_srcs(int source_num, char **argv)
{
	t_source	*srcs;
	int			j;

	srcs = ft_memalloc(sizeof(t_source) * source_num);
	if (!srcs)
		return (NULL);
	j = 0;
	if (!check_p_s(srcs, &j, argv))
		return (NULL);
	if (check_flag('p') || !j)
	{
		srcs[j].src = take_stdin();
		if (!srcs[j].src)
			return (NULL);
		set_src_params(srcs, srcs[j].src, &j, INPUT);
	}
	return (srcs);
}

static int	fill_hash(char **argv, t_data *data)
{
	if (ft_strequ(argv[1], "md5"))
		data->hash = MD5;
	else if (ft_strequ(argv[1], "sha256"))
		data->hash = SHA256;
	else if (ft_strequ(argv[1], "sha512"))
		data->hash = SHA512;
	else if (ft_strequ(argv[1], "whirlpool"))
		data->hash = WHIRLPOOL;
	else
	{
		ft_putstr("Hash algorithm not known\n");
		return (0);
	}
	return (1);
}

t_data	*init(char **argv, int argn)
{
	t_data	*data;
	int		i;

	data = (t_data *)ft_memalloc(sizeof(t_data));
	if (!data)
		return (NULL);
	i = set_flags(argv, data);
	if (!i)
		return (NULL);
	if (!(fill_hash(argv, data)))
		return (NULL);
	data->source_num = check_flag('p') + argn - i;
	if (!data->source_num)
		data->source_num += 1;
	data->srcs = fill_srcs(data->source_num, argv + i);
	if (!(data->srcs))
		return (NULL);
	return (data);
}
