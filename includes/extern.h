/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:43:39 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 14:49:58 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERN_H
# define EXTERN_H

t_wrap (*g_algo_func[4])(t_wrap) = {
md5, sha256, sha512, whirlpool};
const char	g_algo_str[][20] = {
	"md5", "sha256", "sha512", "whirlpool", ""};
const int	g_algo_num[] = {
	16, 32, 64, 64};
#endif