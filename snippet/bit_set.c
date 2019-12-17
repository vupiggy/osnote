unsigned int
hw_slowest(unsigned int w)
{
	unsigned int count;
	
	for (count = 0; w; w >>= 1)
		count += w & 1;
	
	return count;
}
unsigned int
hw_slow(unsigned int w)
{
	unsigned int count;
	
	for (count = 0; w; count++)
		w = w & (w - 1);
	
	return count;
}
unsigned int
hw_fast(unsigned int w)
{
	unsigned int res = (w & 0x55555555) + ((w >> 1) & 0x55555555);
        res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
        res = (res & 0x0F0F0F0F) + ((res >> 4) & 0x0F0F0F0F);
        res = (res & 0x00FF00FF) + ((res >> 8) & 0x00FF00FF);
	res = (res & 0x0000FFFF) + ((res >> 16) & 0x0000FFFF);
	return res;
}
unsigned int
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
static unsigned long
hweight64(unsigned long w)
{
	uint64_t res;
#if 0
	res = w − (w >> 1) & 0x5555555555555555UL;
#else       
	res = (w & 0x5555555555555555ul) + ((w >> 1) & 0x5555555555555555ul);
#endif
	res = (res & 0x3333333333333333ul) + ((res >> 2) & 0x3333333333333333ul);
	res = (res & 0x0F0F0F0F0F0F0F0Ful) + ((res >> 4) & 0x0F0F0F0F0F0F0F0Ful);
#ifdef FAST_MULTIPLICATION
	return (res * 0x0101010101010101ul) >> 56;
#else
	res = (res & 0x00FF00FF00FF00FFul) + ((res >> 8) & 0x00FF00FF00FF00FFul);
	res = (res & 0x0000FFFF0000FFFFul) + ((res >> 16) & 0x0000FFFF0000FFFFul);
	return (res & 0x00000000FFFFFFFFul) + ((res >> 32) & 0x00000000FFFFFFFFul);
#endif
}
