static void
flip_bits(void *data, size_t sz)
{
	char 		*p = data;
	size_t		bytes;
	unsigned char	init_xor_bits = 0x92;

	for (bytes = 0; bytes < sz; bytes++, p++)
		*p ^= init_xor_bits >> (bytes % 3);
}
