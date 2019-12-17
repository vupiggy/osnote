int maxProfit(int[] prices)
{
    int len = prices.length;
    if (len <= 1)
	return 0;

    int[] maxFromHead = new int[len];
    maxFromHead[0] = 0;
    
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < len; i++) {
	minPrice = min(prices[i-1], minPrice);
	if (maxProfit < prices[i] - minPrice)
	    maxProfit = prices[i] - minPrice;
	maxFromHead[i] = maxProfit;
    }

    int maxPrice = prices[len - 1];
    int res = maxFromHead[len-1];
    maxProfit = 0;
    for (int i = len - 2; i >= 0; i--) {
	maxPrice = max(maxPrice, prices[i + 1]);
	if (maxProfit < maxPrice - prices[i])
	    maxProfit = maxPrice - prices[i];
	if (res < maxFromHead[i] + maxProfit)
	    res = maxFromHead[i] + maxProfit;
    }

    return res;
}
