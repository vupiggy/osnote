static inline int power_of_2(int v)
{
	return v && !(v & (v - 1));
}
