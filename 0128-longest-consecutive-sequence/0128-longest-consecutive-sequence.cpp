class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        sort(nums.begin(),nums.end());
        int pre = nums[0];
        int cmax = 1,cnt = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == pre) continue;
            if (nums[i] - pre == 1) {
                cnt++;
                cmax = max(cmax, cnt);
            }else cnt = 1;
            pre = nums[i];
        }
        return cmax;
    }
};