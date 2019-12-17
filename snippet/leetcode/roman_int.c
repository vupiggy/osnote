int romanToInt(string s) {
        int map[26];
        map['I'-'A'] = 1; map['V'-'A'] = 5; map['X'-'A'] = 10; map['L'-'A'] = 50; 
        map['C'-'A'] = 100; map['D'-'A'] = 500; map['M'-'A'] = 1000;
        int res = 0, n = s.size();
        s.push_back(s[n-1]);
        for(int i = 0; i < n; i++)
        {
		if(map[s[i]-'A'] >= map[s[i+1]-'A'])
			res += map[s[i]-'A'];
		else res -= map[s[i]-'A'];
        }
        return res;
}

string intToRoman(int num) {
        char romanChar[] = {'I','V','X','L','C','D','M'};
        string res;
        int i = 6, factor = 1000;
        while(num != 0)
        {
		helper(num / factor, &romanChar[i], res);
		i -= 2;
		num %= factor;
		factor /= 10;
        }
        return res;
}
     
void helper(int k, char romanChar[], string &res)
{	// 0 <= k <= 9
        if(k <= 0)
		return;
        else if(k <= 3)
		res.append(k, romanChar[0]);
        else if(k == 4) {
		res.push_back(romanChar[0]);
		res.push_back(romanChar[1]);
        } else if(k <= 8) {
		res.push_back(romanChar[1]);
		res.append(k-5, romanChar[0]);
        } else if(k == 9) {
		res.push_back(romanChar[0]);
		res.push_back(romanChar[2]);
        }
}
