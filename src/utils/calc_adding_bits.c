/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_adding_bits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:41:49 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 17:05:05 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	calc_adding_bits(size_t msg_bits)
{
	int	mod_512;

	if (msg_bits && !(msg_bits % 448))
		return (512);
	mod_512 = msg_bits % 512;
	if (mod_512 > 448)
		return (448 + (512 - mod_512));
	return (448 - mod_512);
}
