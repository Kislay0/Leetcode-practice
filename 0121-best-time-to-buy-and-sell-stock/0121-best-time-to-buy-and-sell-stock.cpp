#include <bits/stdc++.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        int maxi = 0;
        for (int i = 1; i< prices.size(); i++){
            if (prices[i] < mini) mini = prices[i];
            else {
                profit = prices[i] - mini;
                maxi = max(profit, maxi);
            }
        }
        return maxi;
    }
};