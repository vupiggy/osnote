/*---------------- set bit counting (hamming weight) ----------------*/

/* Lookup table is the fastest but memory consuming */

static unsigned int
hweight8(unsigned int w)
{
        unsigned int res = (w & 0x55) + ((w >> 1) & 0x55);
        res = (res & 0x33) + ((res >> 2) & 0x33);
        return (res & 0x0F) + ((res >> 4) & 0x0F);
}

static unsigned int
hweight16(unsigned int w)
{
        unsigned int res = (w & 0x5555) + ((w >> 1) & 0x5555);
        res = (res & 0x3333) + ((res >> 2) & 0x3333);
        res = (res & 0x0F0F) + ((res >> 4) & 0x0F0F);
        return (res & 0x00FF) + ((res >> 8) & 0x00FF);
}

static unsigned int
hweight32(unsigned int w)
{
        unsigned int res = (w & 0x55555555) + ((w >> 1) & 0x55555555);
        res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
        res = (res & 0x0F0F0F0F) + ((res >> 4) & 0x0F0F0F0F);
        res = (res & 0x00FF00FF) + ((res >> 8) & 0x00FF00FF);
	res = (res & 0x0000FFFF) + ((res >> 16) & 0x0000FFFF);
	return res;
}

#include <stdint.h>
static unsigned long
hweight64(unsigned long w)
{
	uint64_t res;
	res = (w & 0x5555555555555555ul) + ((w >> 1) & 0x5555555555555555ul);
	res = (res & 0x3333333333333333ul) + ((res >> 2) & 0x3333333333333333ul);
	res = (res & 0x0F0F0F0F0F0F0F0Ful) + ((res >> 4) & 0x0F0F0F0F0F0F0F0Ful);
	res = (res & 0x00FF00FF00FF00FFul) + ((res >> 8) & 0x00FF00FF00FF00FFul);
	res = (res & 0x0000FFFF0000FFFFul) + ((res >> 16) & 0x0000FFFF0000FFFFul);
	return (res & 0x00000000FFFFFFFFul) + ((res >> 32) & 0x00000000FFFFFFFFul);
}

static unsigned long
hweight64_slow(unsigned long w)
{
	unsigned long c;
	
	for (c = 0; w; c++)
		w &= (w - 1);
	
	return c;
}

/*---------------- Find First bit Set ----------------*/

/* ASM */
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

/* fast approach, binary search */
static unsigned int
ffs(int x)
{
	int r = 0;

	if (!x)
		return 0;

	if (!(x & 0xFFFF)) {
		r += 16;
		x >>= 16;
	}
	if (!(x & 0xFF)) {
		r += 8;
		x >>= 8;
	}
	if (!(x & 0xF)) {
		r += 4;
		x >>= 4;
	}
	if (!(x & 0x3)) {
		r += 2;
		x >>= 2;
	}
	if (!(x & 0x1)) {
		r += 1;
		// x >>= 1;
	}

	return r;
}

/* slow approach, scanning bit by bit */
static unsigned int
ffs_slow(int x)
{
	int r = 0;

	if (x == 0)
		return 0;
	
	while (!(x & (1 << r)))
		r++;

	return (r + 1);
}

/*---------------- driver ----------------*/
#include <stdio.h>

static void
print_binary(unsigned char *c)
{
	int i = 0x80;

	while (i) {
		putchar(*c & i ? '1' : '0');
		i >>= 1;
	}
}

int
main(int argc, char **argv)
{
	return 0;
}
