/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:43:39 by jagarcia          #+#    #+#             */
/*   Updated: 2020/10/02 14:49:58 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# define BUFFER_SIZE 10
# define INPUT 0
# define STRING 1
# define FILE 2
# define MD5 3
# define SHA256 4
# define SHA512 5
# define WHIRLPOOL 6
# define MAX_OFFSET 8

typedef struct	s_source
{
	char		type;
	char		*src;
	char		*name;
}				t_source;

typedef struct	s_data
{
	int			hash;
	int			source_num;
	t_source	*srcs;
	char		*output_file;
}				t_data;

typedef union	u_wrap{
	char		*c;
	u_char		*uc;
	u_int		*i;
	u_long		*l;
	size_t		*s;
}				t_wrap;

int				main(int a, char **b);
char			check_flag(int a);
int				set_flags(char **a, t_data *b);
char			*read_input(void);
t_wrap			md5_append_bits(t_wrap a, size_t b);
t_wrap			sha256_append_bits(t_wrap a, size_t b);
t_wrap			sha512_append_bits(t_wrap a, size_t b);
t_wrap			whirlpool_append_bits(t_wrap b, size_t a);
t_wrap			md5_append_length(t_wrap a, size_t b, size_t c);
t_wrap			sha256_append_length(t_wrap a, size_t b, size_t c);
t_wrap			sha512_append_length(t_wrap a, size_t b, size_t c);
t_wrap			whirlpool_append_length(t_wrap a, size_t b, size_t c);
size_t			ultra_strlen(char *a);
t_wrap			md5_create_buffer(void);
t_wrap			sha256_create_buffer(void);
t_wrap			sha512_create_buffer(void);
t_wrap			whirlpool_create_buffer(void);
t_wrap			md5_process_message(t_wrap a, size_t b, t_wrap c);
t_wrap			sha512_process_message(t_wrap a, size_t b, t_wrap c);
t_wrap			sha256_process_message(t_wrap a, size_t b, t_wrap c);
t_wrap			whirlpool_process_message(t_wrap a, size_t b, t_wrap c);
char			**get_files(int c, char **b, int a, t_data *d);
t_wrap			md5(t_wrap a);
t_wrap			sha256(t_wrap a);
t_wrap			sha512(t_wrap a);
t_wrap			whirlpool(t_wrap a);
void			print_hex(u_char *a, t_source b, int c, char *d);
t_data			*init(char **a, int b);
int				take_file(char *a, char **b);
char			*take_stdin(void);
int				read_file(int a, char **b);
int				calc_adding_bits(size_t a);
void			*little_to_big(void *a, size_t b, size_t c);
unsigned char	gf_mult(unsigned char b, unsigned char a);
#endif
