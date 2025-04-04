class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return (max(nums[0], nums[1]) > nums[2]) ? max(nums[0], nums[1]) : nums[2];
        vector<int>dp (n);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        for (int i = 3; i< n-1; i++){
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        }
        int max1 = max(dp[n-2], dp[n-3]);
        dp[2] = max(nums[2], nums[1]);
        for (int i = 3; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return max(max1, dp.back());
    }
};