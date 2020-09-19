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
}				t_data;

typedef union u_wrap{
	char	*c;
	u_char	*uc;
	u_int	*i;
	u_long	*l;
	size_t	*s;
} t_wrap;

int		main(int, char**);
char	check_flag(int);
int		set_flags(char **);
char	*read_input(void);
t_wrap	md5_append_bits(t_wrap, size_t);
t_wrap	sha256_append_bits(t_wrap, size_t);
t_wrap	sha512_append_bits(t_wrap, size_t);
t_wrap	md5_append_length(t_wrap, size_t, size_t);
t_wrap	sha256_append_length(t_wrap, size_t, size_t);
t_wrap	sha512_append_length(t_wrap, size_t, size_t);
size_t	ultra_strlen(char *);
t_wrap	md5_create_buffer(void);
t_wrap	sha256_create_buffer(void);
t_wrap	sha512_create_buffer(void);
t_wrap	md5_process_message(t_wrap, size_t, t_wrap);
t_wrap	sha512_process_message(t_wrap, size_t, t_wrap);
t_wrap	sha256_process_message(t_wrap, size_t, t_wrap);
char	**get_files(int, char**, int, t_data *);
t_wrap	md5(t_wrap);
t_wrap	sha256(t_wrap);
t_wrap	sha512(t_wrap);
void	print_hex(u_char *, t_source, int);
t_data	*init(char **, int);
int		take_file(char *, char **);
char	*take_stdin(void);
int		read_file(int, char **);
int		calc_adding_bits(size_t);
void	*little_to_big(void *,size_t, size_t);
#endif
