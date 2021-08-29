/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:40:32 by jagarcia          #+#    #+#             */
/*   Updated: 2021/08/29 02:10:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

size_t	take_stdin(char **input)
{
	size_t	total_ro;

	*input = NULL;
	total_ro = read_file(0, input);
	if (!*input)
		return (0);
	return (total_ro);
}

size_t	take_file(char *filename, char **files)
{
	int		fd;
	size_t	total_ro;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		*files = NULL;
	else
	{
		total_ro = read_file(fd, files);
		if (!*files)
			return (0);
		return (total_ro);
	}
	return (0);
}
