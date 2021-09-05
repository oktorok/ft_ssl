/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2021/08/29 22:08:44 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	set_src_params(t_source *srcs, char *name, size_t size, int input)
{
	srcs->name = name;
	srcs->type = input;
	srcs->size = size;
}

static int	check_p_s(t_source *srcs, int *j, char **argv)
{
	char	*tmp_s;
	int		i;
	size_t	total_ro;

	if (check_flag('s'))
		tmp_s = ft_strdup(*argv++);
	i = *j;
	while (argv[i])
		i++;
	while (--i + 1)
	{
		total_ro = take_file(argv[i], &srcs[*j].src);
		set_src_params(srcs + (*j)++, argv[i], total_ro, FILE);
	}
	if (check_flag('s'))
	{
		srcs[*j].src = tmp_s;
		if (!srcs[*j].src)
			return (0);
		set_src_params(srcs + (*j), srcs[*j].src, ultra_strlen(tmp_s), STRING);
		(*j)++;
	}
	return (1);
}

static t_source	*fill_srcs(int source_num, char **argv)
{
	t_source	*srcs;
	int			j;
	size_t		total_ro;

	srcs = ft_memalloc(sizeof(t_source) * source_num);
	if (!srcs)
		return (NULL);
	j = 0;
	if (!check_p_s(srcs, &j, argv))
	{
		free(srcs);
		return (NULL);
	}
	if (check_flag('p') || !j)
	{
		total_ro = take_stdin(&srcs[j].src);
		if (!srcs[j].src)
		{
			free(srcs);
			return (NULL);
		}
		set_src_params(srcs + j, srcs[j].src, total_ro, INPUT);
		j++;
	}
	return (srcs);
}

static int	fill_hash(char **argv, t_data *data)
{
	data->hash = 0;
	while (1)
	{
		if (ft_strequ(argv[1], g_algo_str[data->hash]))
			break ;
		data->hash++;
		if (!(g_algo_str[data->hash][0]))
		{
			ft_putstr("Hash algorithm not known\n");
			return (0);
		}
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
	data->output_fd = 0;
	i = set_flags(argv, data);
	if (!i)
		return (free_error(data));
	if (!(fill_hash(argv, data)))
		return (free_error(data));
	data->source_num = check_flag('p') + argn - i;
	if (!data->source_num)
		data->source_num += 1;
	data->srcs = fill_srcs(data->source_num, argv + i);
	if (!(data->srcs))
		return (free_error(data));
	return (data);
}
