#include "ft_ssl.h"

char	*take_stdin()
{
	char *input;

	input = NULL;
	if (!read_file(0, &input))
		return (NULL);
	return (input);
}

int		take_file(char *filename, char **files)
{
	int		fd;
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		*files = NULL;
	else
		return (read_file(fd, files));
	return (0);
}
