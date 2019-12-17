class Solution {
public:
	vector<string> generateParenthesis(int n)
	{
		string tmpres;
		vector<string> res;
		helper(tmpres, res, n, n);
		return res;
	}
private:
	void helper(string &tmpres, vector<string>&res, int leftNum, int rightNum)
	{
		if (leftNum > rightNum) return;
		if (leftNum == 0 && rightNum == 0) {
			res.push_back(tmpres);
			return;
		}
		if (leftNum > 0) {
			tmpres.push_back('(');
			helper(tmpres, res, leftNum-1, rightNum);
			tmpres.pop_back();
		}
		if(rightNum > 0) {
			tmpres.push_back(')');
			helper(tmpres, res, leftNum, rightNum-1);
			tmpres.pop_back();
		}
	}
};
