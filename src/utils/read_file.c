/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:49 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:14:35 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

size_t	read_file(int fd, char **content)
{
	int		ro;
	size_t	total_ro;
	char	buffer[BUFFER_SIZE];

	ro = 1;
	total_ro = 0;
	while (1)
	{
		ro = read(fd, buffer, BUFFER_SIZE);
		if (ro < 0)
		{
			if (*content)
				ft_strdel(content);
			return (0);
		}
		*content = ft_memrealloc(*content, total_ro, ro + total_ro);
		if (!ro)
			break ;
		if (!(*content))
			return (0);
		ft_memcpy(*content + total_ro, buffer, ro);
		total_ro += ro;
	}
	return (total_ro);
}
