vector<string> letterCombinations(string digits) {
	vector<string> res;
	string tmpres(digits.size(), ' ');
	dfs(digits, 0, tmpres, res);
	return res;
}
     
void dfs(const string &digits, int index, string &tmpres, vector<string>&res)
{
	string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	if(index == digits.size())
	{
		res.push_back(tmpres);
		return;
	}
	for(int i = 0; i < numap[digits[index] - '0'].size(); i++)
	{
		tmpres[index] = numap[digits[index] - '0'][i];
		dfs(digits, index+1, tmpres, res);
	}
}
