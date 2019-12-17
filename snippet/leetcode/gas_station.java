public int canCompleteCircuit(int[] gas, int[] cost)
{
	if(gas==null || gas.length==0 || cost==null ||
	   cost.length==0 || gas.length!=cost.length)
		return -1;
	
	int	sum	= 0;
	int	total	= 0;
	int	pointer = -1;
	
	for(int i = 0;i < gas.length; i++) {
		int diff = gas[i] - cost[i];
		sum += diff;
		total += diff;
		if(sum < 0) {
			sum = 0;
			pointer = i;
		}
	}
	return total >= 0 ? pointer + 1 : -1;
}
