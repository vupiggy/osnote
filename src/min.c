#define min(x, y) ({						\
			typeof(x) _min1 = (x);			\
			typeof(y) _min2 = (y);			\
			(void) (&_min1 == &_min2);		\
			_min1 < _min2 ? _min1 : _min2; })


