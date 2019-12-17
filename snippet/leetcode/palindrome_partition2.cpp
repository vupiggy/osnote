int minCut(string s) {
        int len = s.length();
        if(len <= 1)return 0;

        bool **f = new bool*[len];
        for(int i = 0 ; i < len; i++)
        {
		f[i] = new bool[len+1];
		for(int j = 0; j < len+1; j++)
			f[i][j] = false;
		f[i][1] = true;
        }
        int mins[len];// 子串 s[0...i] 的最小分割次数
        mins[0] = 0;
        for(int k = 2; k <= len; k++) {
		for(int i = 0; i <= len-k; i++)	{
			if(k == 2)
				f[i][2] = (s[i] == s[i+1]);
			else
				f[i][k] = f[i + 1][k - 2] &&
					s[i] == s[i + k - 1];
		}
		
		if (f[0][k] == true) {
			mins[k-1] = 0;
			continue;
		}
		
		mins[k-1] = len - 1;
		for(int i = 0; i < k-1; i++) {
			int tmp;
			if(f[i+1][k-i-1] == true)
				tmp = mins[i]+1;
			else
				tmp = mins[i] + k - i - 1;
			
			if(mins[k - 1] > tmp)
				mins[k - 1] = tmp;
		}
        }
        for(int i = 0 ; i < len; i++)
		delete [](f[i]);
        delete []f;
	
        return mins[len-1];
}
