vector<int> plusOne(vector<int> &digits) {
	int len = digits.size();
	vector<int> res(digits);
	int carrybit = 1, i;
	
	for (i = len-1; carrybit && i >= 0; i--) {
		res[i] += carrybit;
		if(res[i] >= 10) {
			carrybit = 1;
			res[i] -= 10;
		}
		else
			carrybit = 0;
	}
	
	if (i < 0 && carrybit == 1)
		res.insert(res.begin(), carrybit);
	
	return res;
}
