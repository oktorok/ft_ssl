#include "ft_ssl.h"

t_source	*fill_srcs(int source_num, char **argv)
{
	t_source	*srcs;
	int			j;
	
	if (!(srcs = ft_memalloc(sizeof(t_source) * source_num)))
		return (NULL);
	j = 0;
	if (!source_num || check_flag('p'))
	{
		if (!(srcs[j].src = take_stdin()))
			return (NULL);
		srcs[j].name = srcs[j].src;
		srcs[j++].type = INPUT;
	}
	if (check_flag('s'))
	{
		if (!(srcs[j].src = ft_strdup(*argv++)))
			return (NULL);
		srcs[j].name = srcs[j].src;
		srcs[j++].type = STRING;
	}
	while (*argv)
	{
		if (take_file(*argv, &srcs[j].src) < 0)
			return (NULL);
		srcs[j].name = *argv++;
		srcs[j++].type = FILE;
	}
	return (srcs);
}

static int	fill_hash(char **argv, t_data *data)
{
	if (ft_strequ(argv[1],"md5"))
		data->hash = MD5;
	else if (ft_strequ(argv[1],"sha256"))
		data->hash = SHA256;
	else if (ft_strequ(argv[1],"sha512"))
		data->hash = SHA512;	
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

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		return (NULL);
	if (!(i = set_flags(argv)))
		return (NULL);
	if (!(fill_hash(argv, data)))
		return (NULL);
	data->source_num = check_flag('p') + argn - i;
	if (!(data->srcs = fill_srcs(data->source_num, argv + i)))
		return (NULL);
	return (data);
}
