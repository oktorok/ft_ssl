/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:43:39 by jagarcia          #+#    #+#             */
/*   Updated: 2021/08/29 02:19:13 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERN_H
# define EXTERN_H

t_wrap (*g_algo_func[4])(t_wrap, size_t) = {
md5, sha256, sha512, whirlpool};
char		g_algo_str[][20] = {
	"md5", "sha256", "sha512", "whirlpool", ""};
const int	g_algo_num[] = {
	16, 32, 64, 64};
#endif
