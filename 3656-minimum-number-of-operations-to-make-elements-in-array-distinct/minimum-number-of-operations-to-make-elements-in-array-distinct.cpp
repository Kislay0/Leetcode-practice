class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> seen;
        for (int i = nums.size()-1; i>=0; i--){
            if (seen.contains(nums[i])){
                return i/3 + 1;
            }
            seen.insert(nums[i]);
        }
        return 0;
    }
};