class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long maxi = 0;
        vector<long long> dp (n);
        for (int i = n-1; i>= 0; i--){
            dp[i] += questions[i][0];
            if(questions[i][1] + i < n-1){
                dp[i]+= dp[questions[i][1]+1+i];
            }
            maxi = max(dp[i], maxi);
            dp[i] = maxi;
        }
        long long maxsum = 0;
        for (int i = 0; i<n; i++){
            maxsum = max(maxsum, dp[i]);
        }
        return maxsum;
    }
};