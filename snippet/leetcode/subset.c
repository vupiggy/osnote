/* DFS 递归 */
class Solution {
private:
	vector<vector<int> >res;
public:
	vector<vector<int> > subsets(vector<int> &S) {
		// 先排序，然后dfs每个元素选或者不选，最后叶子节点就是所有解
		res.clear();
		sort(S.begin(), S.end());
		vector<int>tmpres;
		dfs(S, 0, tmpres);
		return res;
	}
	void dfs(vector<int> &S, int iend, vector<int> &tmpres)
	{
		if(iend == S.size()) {
			res.push_back(tmpres);
			return;
		}
		// 选择S[iend]
		tmpres.push_back(S[iend]);
		dfs(S, iend+1, tmpres);
		tmpres.pop_back();
		// 不选择S[iend]
		dfs(S, iend+1, tmpres);
	}
};

/* DFS 非递归 */
vector<vector<int> > subsets(vector<int> &S)
{
	int len = S.size();
	sort(S.begin(), S.end());
	vector<vector<int> > res(1); // 加入一个空集
	for(int i = 0; i < len; ++i) {
		int resSize = res.size();
		for(int j = 0; j < resSize; j++) {
			res.push_back(res[j]);
			res.back().push_back(S[i]);
		}
	}
	return res;
}

class Solution {
private:
	vector<vector<int> >res;
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		int len = S.size();
		sort(S.begin(), S.end());
		vector<vector<int> > res(1);   // 加入空集
		int last = S[0], opResNum = 1; // 上一个数字、即将要进行操作的子集数量
		for(int i = 0; i < len; ++i) {
			if(S[i] != last) {
				last = S[i];
				opResNum = res.size();
			}
			// 如果有重复数字，将操作的子集的数目和上次相同
			int resSize = res.size();
			for(int j = resSize-1; j >= resSize - opResNum; j--) {
				res.push_back(res[j]);
				res.back().push_back(S[i]);
			}
		}
		return res;
	}
};
