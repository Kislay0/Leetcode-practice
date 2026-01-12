class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size()== 0) return 0;
        int lo = 0, hi = nums.size()-1;
        while (hi>lo && nums[hi] == val){
            hi--;
        }
        while(hi>lo){
            if (nums[lo] == val){
                swap(nums[lo], nums[hi]);
                while (hi>lo && nums[hi] == val){
                    hi--;
                }
            }
            lo++;
        }
        if (nums[lo] == val) return lo;
        return lo+1;
    }
};