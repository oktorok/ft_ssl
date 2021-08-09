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

int	read_file(int fd, char **content)
{
	int		ro;
	int		len;
	char	buffer[BUFFER_SIZE];

	ro = 1;
	while (1)
	{
		ro = read(fd, buffer, BUFFER_SIZE);
		if (ro < 0)
		{
			if (content)
				free(content);
			return (-1);
		}
		len = ft_strlen(*content);
		*content = ft_strrealloc(content, ro + len);
		if (!(*content))
			return (-1);
		else if (!ro)
			break ;
		ft_strncpy(*content + len, buffer, ro);
	}
	return (1);
}
