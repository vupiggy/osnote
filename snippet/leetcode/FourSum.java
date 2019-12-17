public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target)
{
    ArrayList<ArrayList<Integer>> res =
			new ArrayList<ArrayList<Integer>>();
    if (num==null||num.length==0)
        return res;
    
    Arrays.sort(num);
    
    for (int i = num.length - 1; i > 2; i--) {
        if (i == num.length-1 || num[i] != num[i+1]) {
            ArrayList<ArrayList<Integer>> curRes =
			threeSum(num, i - 1, target - num[i]);
            for (int j = 0; j < curRes.size(); j++)
                curRes.get(j).add(num[i]);

            res.addAll(curRes);  
        }
    }
    
    return res;          
}

private ArrayList<ArrayList<Integer>>
threeSum(int[] numbers, int end, int target)
{
    ArrayList<ArrayList<Integer>> res =
			new ArrayList<ArrayList<Integer>>();

    if (numbers == null || numbers.length<=2)
        return res;
    
    for (int i = end; i > 1; i--) {
	if(i==end || num[i]!=num[i+1]) {
            ArrayList<ArrayList<Integer>> curRes =
			twoSum(num, i - 1, target - num[i]);
            for(int j = 0; j < curRes.size(); j++)
                curRes.get(j).add(num[i]);

	    res.addAll(curRes);
	}
    }
    
    return res;
}

private ArrayList<ArrayList<Integer>>
twoSum(int[] numbers, int end,int target)
{
    if(numbers==null || numbers.length<=1)
        return res;
    
    ArrayList<ArrayList<Integer>> res =
			new ArrayList<ArrayList<Integer>>();
    int l = 0;
    int r = end;
    
    while (l < r) {
        if (numbers[l] + numbers[r] == target) {
            ArrayList<Integer> item =
			new ArrayList<Integer>();
            item.add(numbers[l]);
            item.add(numbers[r]);
            res.add(item);
            l++;
            r--;
            while (l < r && numbers[l] == numbers[l - 1])
                l++;
            while (l < r && numbers[r] == numbers[r + 1])
                r--;
        } else if (numbers[l] + numbers[r] > target)
            r--;
        else
            l++;
    }
    return res;
}
