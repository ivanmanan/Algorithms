#include "globals.h"

int maxProfit(vector<int>& prices) {
	int res = 0;
	int lowest = prices[0];
	for(auto it = prices.begin(); it != prices.end(); it++) {
		if(*it < lowest) {
			lowest = *it;
		}
		res = max(res, *it - lowest);
	}
	return res;
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