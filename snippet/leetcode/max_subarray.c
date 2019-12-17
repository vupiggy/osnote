#define max(x, y) ({			\
      	typeof(x) _x = (x);		\
	typeof(y) _y = (y);		\
	(void) (&_x == &_y);		\
	_x > _y ? _x : _y; })

int
max_sum_subarray(int array[], int n)
{
	int i;
	int prev;
	int max;
    
	max = prev = array[0];
    	
	for (i = 1; i < n; i++) {
		prev = max(prev + array[i], array[i]);
    
		if (prev > max)
			max = prev;
	}
    
	return max;
}
