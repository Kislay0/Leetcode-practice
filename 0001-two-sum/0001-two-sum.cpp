class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> dif;
        for (int i = 0; i<nums.size(); i++){
            if (dif.find(nums[i]) != dif.end()){
                return {dif[nums[i]], i};
            }
            dif[target - nums[i]] = i;
        }
        return{-1,-1};
    }
};