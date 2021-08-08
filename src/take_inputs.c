/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:03:50 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*take_stdin(void)
{
	char	*input;

	input = NULL;
	if (read_file(0, &input) < 0)
		return (NULL);
	return (input);
}

int	take_file(char *filename, char **files)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		*files = NULL;
	else
		return (read_file(fd, files));
	return (0);
}
