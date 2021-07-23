/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:13:30 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 15:17:04 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

const char			*g_operations[] = {
	"ABCD F  0  7  1", "DABC F  1 12  2", "CDAB F  2 17  3", "BCDA F  3 22  4",
	"ABCD F  4  7  5", "DABC F  5 12  6", "CDAB F  6 17  7", "BCDA F  7 22  8",
	"ABCD F  8  7  9", "DABC F  9 12 10", "CDAB F 10 17 11", "BCDA F 11 22 12",
	"ABCD F 12  7 13", "DABC F 13 12 14", "CDAB F 14 17 15", "BCDA F 15 22 16",
	"ABCD G  1  5 17", "DABC G  6  9 18", "CDAB G 11 14 19", "BCDA G  0 20 20",
	"ABCD G  5  5 21", "DABC G 10  9 22", "CDAB G 15 14 23", "BCDA G  4 20 24",
	"ABCD G  9  5 25", "DABC G 14  9 26", "CDAB G  3 14 27", "BCDA G  8 20 28",
	"ABCD G 13  5 29", "DABC G  2  9 30", "CDAB G  7 14 31", "BCDA G 12 20 32",
	"ABCD H  5  4 33", "DABC H  8 11 34", "CDAB H 11 16 35", "BCDA H 14 23 36",
	"ABCD H  1  4 37", "DABC H  4 11 38", "CDAB H  7 16 39", "BCDA H 10 23 40",
	"ABCD H 13  4 41", "DABC H  0 11 42", "CDAB H  3 16 43", "BCDA H  6 23 44",
	"ABCD H  9  4 45", "DABC H 12 11 46", "CDAB H 15 16 47", "BCDA H  2 23 48",
	"ABCD I  0  6 49", "DABC I  7 10 50", "CDAB I 14 15 51", "BCDA I  5 21 52",
	"ABCD I 12  6 53", "DABC I  3 10 54", "CDAB I 10 15 55", "BCDA I  1 21 56",
	"ABCD I  8  6 57", "DABC I 15 10 58", "CDAB I  6 15 59", "BCDA I 13 21 60",
	"ABCD I  4  6 61", "DABC I 11 10 62", "CDAB I  2 15 63", "BCDA I  9 21 64"
};
const unsigned int	g_t[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x2441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x4881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};
#endif
