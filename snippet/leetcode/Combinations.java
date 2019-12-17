public ArrayList<ArrayList<Integer>> combinations(int n, int k) {
    ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
    if (n <= 0 || n < k)
        return res;
    
    /* 原始问题集合 [1...n] */
    combinations(1, n, k, new ArrayList<Integer>(), res);
    return res;
}

private void combinations(int begin, int end, int k, 
                          ArrayList<Integer> combination,
                          ArrayList<ArrayList<Integer>> res)
{
    if (k == 0) {
        res.add(new ArrayList<Integer>(item));
        return;
    }
    
    for (int i = begin; i <= end; i++) {
	/* 当 i 属于一个组合，i 之后元素取 k - 1 的组合构成一系列解 */
        combination.add(i);
        combinations(i + 1, end, k - 1,, combination, res);
        combination.remove(item.size() - 1);
    }
}
