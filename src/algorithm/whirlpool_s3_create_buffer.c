/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool_s3_create_buffer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:33 by jagarcia          #+#    #+#             */
/*   Updated: 2021/08/30 02:54:18 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_wrap	whirlpool_create_buffer(void)
{
	t_wrap	buffer;

	buffer.uc = (unsigned char *)ft_memalloc(sizeof(char) * 64);
	ft_bzero(buffer.uc, sizeof(char) * 64);
	if (!buffer.uc)
		return (buffer);
	return (buffer);
}
