#include "ft_ssl.h"
#include <stdlib.h>

static t_wrap	hashing(t_wrap digest, int hash)
{
	t_wrap	output;

	if (hash == MD5)
		output = md5(digest);
	else if (hash == SHA256)
		output = sha256(digest);
	else if (hash == SHA512)
		output = sha512(digest);
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
	ft_putstr(src.name);
	ft_putendl(": No such file or directory");
}

int main(int argn, char **argv)
{
	t_data	*data;
	int		j;
	t_wrap	digest;
	t_wrap	output;

	if (argn < 2)
	{
		ft_putendl("ft_ssl: Incorrect format, write -h or --help for an explanation of the correct format");
		return (-1);
	}
	if (!(data = init(argv, argn)))
		return (-1);
	j = 0;
	while (j < data->source_num)
	{
		digest.c = data->srcs[j].src;
		if (digest.c)
		{
			output = hashing(digest, data->hash);
			if (!output.c)
				return (-1);
			print_hex(output.uc, data->srcs[j++], data->hash);
		}
		else
			print_error(data->srcs[j++], data->hash);
	}
	return (1);
}
