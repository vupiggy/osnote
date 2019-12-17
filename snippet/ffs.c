/* Find First Set */
int
ffs_slow(unsigned int v)
{
	int res = 0;

	if (v == 0)
		return 0;

	for (res = 0; !(v & (1 << res)); res++);
	return res + 1;
}
int
ffs(unsigned int v)
{
	int res = 1;

	if (!x)
		return 0;

	if (!(x & 0xffffu)) {
		r += 16;
		x >>= 16;
	}
	if (!(x & 0xffu)) {
		r += 8;
		x >>= 8;
	}
	if (!(x & 0xfu)) {
		r += 4;
		x >>= 4;
	}
	if (!(x & 0x3u)) {
		r += 2;
		x >>= 2;
	}
	if (!(x & 0x1u)) {
		r += 1;
		// x >>= 1;
	}

	return r;
	
}
/* Find Last Set*/
int
fls_slow(unsigned int v)
{
	int res;

	if (v == 0)
		return 0;

	for (res = 31; !(v & (1 << res)); res--);
	return res + 1;
}
int
fls(int x)
{
	int r = 32;

	if (!x)
		return 0;
	if (!(x & 0xffff0000u)) {
		x <<= 16;
		r -= 16;
	}
	if (!(x & 0xff000000u)) {
		x <<= 8;
		r -= 8;
	}
	if (!(x & 0xf0000000u)) {
		x <<= 4;
		r -= 4;
	}
	if (!(x & 0xc0000000u)) {
		x <<= 2;
		r -= 2;
	}
	if (!(x & 0x80000000u)) {
		x <<= 1;
		r -= 1;
	}
	return r;
}
/* assembler */
static unsigned int
ffs_asm(unsigned long w)
{
	__asm__("bsfq %1,%0"
		:"=r" (w)
		:"rm" (w));
	return w;
	
}

/* Find First Zero, apply FFS on ~w */
static unsigned int
ffz_asm(unsigned long w)
{
	__asm__("bsfq %1,%0"
		:"=r" (w)
		:"rm" (~w));
	return w;
	
}
