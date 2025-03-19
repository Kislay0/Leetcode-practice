class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = upper_bound (nums.begin(), nums.end(),0) -nums.begin();
        pos = nums.size()- pos;
        int neg = lower_bound(nums.begin(), nums.end(),0) -nums.begin();
        return (pos>neg) ? pos : neg;
    }
};