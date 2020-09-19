#include "ft_ssl.h"

static void	print_help_func()
{
	ft_putstr("command: ft_ssl [ALGORITHM] [OPTIONS] [FILES]\n\n");
	ft_putstr("ALGORITHMS:\n\tmd5\n\tsha256\n\n");
	ft_putstr("OPTIONS:\n\t-h: help\n\t-p: echo STDIN to STDOUT and append the checksum to STDOUT\n\t-q: quiet mode\n\t-r: reverse the format of the output.\n\t-s: print the sum of the given string\n");
}

int	set_flags(char **argv)
{
	int	flags;
	int	ns;
	int	i;

	flags = 0;
	ns = 0;
	i = ((argv[1][0] == '-') ? 1 : 2);
	while (argv[i] && argv[i][0] == '-')
	{
		while (argv[i][ns] == '-')
			ns++;
		if (!argv[i][ns] || ft_tolower(argv[i][ns]) == 'h')
		{
			print_help_func();
			return (0);
		}
		flags |= (1 << (argv[i++][ns] - 'a'));
	}
	if (!flags)
		flags |= (1 << ('p' - 'a'));
	check_flag(flags);
	return (i);
}

char	check_flag(int to_check)
{
	static int flags = -1;

	if (flags < 0)
	{
		flags = to_check;
		return (0);
	}
	if (flags & (1 << (to_check - 'a')))
		return (1);
	return (0);
}
