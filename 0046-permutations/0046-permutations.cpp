class Solution {
    void sol(vector<int>& nums, vector<bool>& seen, vector<int>&subset, vector<vector<int>>& ans){
        if (subset.size() == nums.size()) {
            ans.push_back(subset);
            return;
        }
        for (int i = 0; i<nums.size(); i++){
            if(seen[i]) continue;
            subset.push_back(nums[i]);
            seen[i] = true;
            sol(nums, seen, subset, ans);
            seen[i] = false;
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> seen(nums.size(), false);
        vector<int> subset;
        vector<vector<int>> ans;
        sol(nums, seen, subset, ans);
        return ans;
    }
};