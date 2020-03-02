#include "globals.h"

// Part I
int maxProfitI(vector<int>& prices) {
	if (prices.size() == 1 || prices.empty()) return 0;
	int maxprofit = 0, len = prices.size();
	vector<int> Rmax (len, 0);
	Rmax[len-1] = prices[len-1];
	for (int i = len - 2; i >= 0; --i)      // obtain the Rmax array
		Rmax[i] = max (prices[i], Rmax[i+1]);

	for (int i = 0; i < len; ++i)          // obtain max profit
		maxprofit = max (maxprofit, Rmax[i] - prices[i]);

	return maxprofit;
}


// Part II
int maxProfitII(vector<int>& prices) {
	int maxprofit = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[i - 1])
			maxprofit += prices[i] - prices[i - 1];
	}
	return maxprofit;
}