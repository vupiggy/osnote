vector<vector<string>> partition(string s)
{
	vector< vector<string> >res;
	int len = s.length();
	if(len == 0)
		return res;

	bool **f = new bool *[len];
	for(int i = 0 ; i < len; i++) {
		f[i] = new bool[len+1];
		for(int j = 0; j < len+1; j++)
			f[i][j] = 0;
		f[i][1] = true;
	}
	
	for(int k = 2; k <= len; k++) {
		for (int i = 0; i <= len-k; i++) {
			if (k == 2)
				f[i][2] = (s[i] == s[i + 1]);
			else
				f[i][k] = f[i + 1][k - 2] &&
					(s[i] == s[i + k - 1]);
		}
	}
	
	vector<string> tmp;
	DFSRecur(s, f, 0, res, tmp);
	for(int i = 0 ; i < len; i++)
		delete [](f[i]);
	delete []f;
	return res;
}
    
void DFSRecur(const string &s, bool **f, int i, 
	      vector< vector<string> > &res, vector<string> &tmp)
{
	int len = s.length();
	if (i >= len) {
		res.push_back(tmp);
		return;
	}
	
	for (int k = 1; k <= len - i; k++)
		if (f[i][k] == true) {
			tmp.push_back(s.substr(i, k));
			DFSRecur(s, f, i + k, res, tmp);
			tmp.pop_back();
		}                
}
