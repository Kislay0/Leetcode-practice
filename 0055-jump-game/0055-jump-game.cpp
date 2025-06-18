class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        if (nums[0] == 0 && n > 1) return false;
        int cnt = nums[0]-1;
        for (int i = 1; i<n; i++){
            cnt = max(nums[i], cnt);
            if (cnt == 0 && i<n-1) return false;
            cnt--;
        }
        return true;
    }
};