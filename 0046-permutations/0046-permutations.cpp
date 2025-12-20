class Solution {
    void sol(vector<int>& nums, int depth, vector<vector<int>>& ans){
        if (depth == nums.size()) {
            ans.push_back(nums);
            return;
        } 
        for (int i = depth; i<nums.size(); i++){
            swap(nums[i], nums[depth]);
            sol(nums, depth + 1, ans);
            swap(nums[i], nums[depth]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<bool> seen(nums.size(), false);
        // vector<int> subset;
        vector<vector<int>> ans;
        sol(nums, 0, ans);
        return ans;
    }
};

