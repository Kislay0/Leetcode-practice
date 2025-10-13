class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = INT_MAX, ans = 0;
        for (int p: prices){
            maxi = min(p, maxi);
            ans = max(ans, p-maxi);
        }
        return ans;
    }
};