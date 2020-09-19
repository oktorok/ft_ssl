#include "ft_ssl.h"

t_wrap	 md5_create_buffer(void)
{
	t_wrap	 buffer;

	if (!(buffer.i = (uint *)ft_memalloc(sizeof(uint) * 4)))
		return (buffer);
	buffer.i[0] = 0x67452301;
	buffer.i[1] = 0xefcdab89;
	buffer.i[2] = 0x98badcfe;
	buffer.i[3] = 0x10325476;
	return (buffer);
}
