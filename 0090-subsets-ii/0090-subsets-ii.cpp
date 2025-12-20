class Solution {
    void sol(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& ans){
        ans.push_back(subset);
        for (int i = index; i<nums.size(); i++){
            if (i>index && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            sol(nums, i+1, subset, ans);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>subset;
        vector<vector<int>> ans;
        sol(nums, 0, subset, ans);
        return ans;
    }
};