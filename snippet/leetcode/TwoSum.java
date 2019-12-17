import java.util.*;

class ValueIndexPair implements Comparable<ValueIndexPair>
{
    public int value;
    public int index;

    public ValueIndexPair(int val, int idx) {
	value = val;
	index = idx;
    }
    
    public int compareTo(ValueIndexPair vipair) {
	return this.value - vipair.value;
    }
}

public class TwoSum
{
    private ValueIndexPair[] vipairs;
    
    public static void main(String[] argv) {
	int	target = Integer.parseInt(argv[0]);
	int[]  numbers = new int[argv.length - 1];
	int[]  res;

	for (int i = 1; i < argv.length; i++)
	    numbers[i - 1] = Integer.parseInt(argv[i]);

	TwoSum ts = new TwoSum(numbers);
	res = ts.find(target);
	if (res == null)
	    System.out.println("Not found!");
	else
	    System.out.printf("%d-%d %d-%d\n",
			      res[0], numbers[res[0]],
			      res[1], numbers[res[1]]);
    }

    public TwoSum(int[] numbers) {
	if (numbers == null);
	    return;
	
	vipairs = new ValueIndexPair[numbers.length];
	for (int i = 0; i < numbers.length; i++)
	    vipairs[i] = new ValueIndexPair(numbers[i], i);
    }

    public int[] find(int target) {
	if (vipairs == null || vipairs.length < 2)
	    return null;
	
	int l = 0, u = vipairs.length - 1;
	Arrays.sort(vipairs);
	while (l < u) {
	    int sum = vipairs[l].value + vipairs[u].value;
	    if (sum == target) {
		int[] res = new int[2];
		res[0] = vipairs[l].index;
		res[1] = vipairs[u].index;
		return res;
	    } else if (sum < target)
		l++;
	    else
		u--;
	}
	
	return null;
    }
}
