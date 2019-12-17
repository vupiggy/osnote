int
reverse_integer(int i)
{
	int res = 0;
	while (i != 0) {
		res = res * 10 + i % 10;
		i /= 10;
	}
	return res;
}

#if 0
/* with overflow check 溢出检查！ */
int reverse(int x) {
	int max_first_bit = 2; // default for 4
	int max_remain_num = 147483647;
        
	int num = 0;
	int temp = abs(x);
	while(temp >= 10){
		num = num * 10 + temp % 10;
		temp /= 10;
	}
        
	switch(sizeof(int)){
	case 1:
		max_first_bit = 1;
		max_remain_num = 27;
		break;
	case 2:
		max_first_bit = 3;
		max_remain_num = 2767;
		break;
	case 4:
		max_first_bit = 2;
		max_remain_num = 147483647;
		break;
	case 8:
		max_first_bit = 9;
		max_remain_num = 223372036854775807;
		break;
	}    
        
	if (x > 0){
		if (temp < max_first_bit || num <= max_remain_num)
			return num * 10 + temp % 10;
		else
			/* return what? */
			} else {
		if (temp < max_first_bit || num <= max_remain_num + 1)
			return 0 - (num * 10 + temp % 10);
		else
			/* return what? */
			}
        
}
#endif
