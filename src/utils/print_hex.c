#include "ft_ssl.h"

static void true_putendl(char *str)
{
	int l;

	l = ft_strlen(str);
	if (str[l - 1] == '\n')
		str[l - 1] = '\0';
	ft_putendl(str);
}

static void print_prolog(int hash, t_source src)
{
	if (src.type == INPUT && check_flag('p'))
		return (true_putendl(src.name));
	if (check_flag('r') || check_flag('q'))
		return;
	if (hash == MD5)
		ft_putstr("MD5 (");
	else if (hash == SHA256)
		ft_putstr("SHA256 (");
	else if (hash == SHA512)
		ft_putstr("SHA512 (");
	if (src.type == STRING)
	{
		ft_putchar('\"');
		ft_putstr(src.name);
		ft_putchar('\"');
	}
	else if (src.type == FILE)
		ft_putstr(src.name);
	ft_putstr(") = ");
}

static void print_epilog(t_source src)
{
	if (check_flag('r') && src.type != INPUT)
	{
		ft_putchar(' ');
		if (src.type == STRING)
		{
			ft_putchar('\"');
			ft_putstr(src.name);
			ft_putchar('\"');
		}
		else if (src.type == FILE)
			ft_putstr(src.name);
	}
}

void print_hex(u_char *output, t_source src, int hash)
{
	char*	t;
	int j;
	int	length;

	if (hash == MD5)
		length = 16;
	else if (hash == SHA256)
		length = 32;
	else if (hash == SHA512)
		length = 64;
	j = 0;
	print_prolog(hash, src);
	while (j < length)
	{
		t = ft_itoa_base(output[j++], 16);
		t = ft_strmap(t, ft_tolower);
		if (ft_strlen(t) != 2)
			ft_putchar('0');
		ft_putstr(t);
		ft_strdel(&t);
	}
	if (!check_flag('q'))
		print_epilog(src);
	ft_putendl("");
}
