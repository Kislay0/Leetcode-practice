class Solution {
private:
    void sol(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }
        // cout<<"\nL1: ";
        // for(int i : subset){
        //     cout<<i<<" ";
        // }
        subset.push_back(nums[index]);
        sol(nums, index + 1, subset, ans);
        // cout<<"\nL2: ";
        // for(int i : subset){
        //     cout<<i<<" ";
        // }
        subset.pop_back();
        sol(nums, index + 1, subset, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sol(nums, 0, subset, ans);
        return ans;
    }
};