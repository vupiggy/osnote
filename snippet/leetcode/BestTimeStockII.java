int totalProfit(int[] prices)
{
    int total_profit = 0;
    
    for (int i = 0; i < prices.length; i++) {
	int profit = prices[i + 1] - prices[i];
	if (profit > 0)
	    total_profit += profit;
    }

    return total_profit;
}
