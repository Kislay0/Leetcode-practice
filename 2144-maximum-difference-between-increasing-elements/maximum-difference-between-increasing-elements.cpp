class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int lo = nums[0];
        int ans = -1;
        for (int i = 1; i< nums.size(); i++){
            if (nums[i]<= lo) lo = nums[i];
            else ans = max(ans, nums[i] - lo);
        }
        return ans;
    }
};