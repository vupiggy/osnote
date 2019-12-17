int maxProfit(int[] prices)
{
    if (prices == null || prices.length == 0)
	return 0;

    int lowest_price = prices[0];
    int max_profit   = 0;

    for (int price : prices) {
	if (price < lowest)
	    lowest_price = price;

	int profit = price - lowest_price;
	
	if (profit > max_profit)
	    max_profit = profit;
    }

    return max_profit;
}
