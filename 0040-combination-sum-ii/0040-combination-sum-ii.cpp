class Solution {
    void sol (vector<int>& candidates, int target, int index, vector<int>& subset, vector<vector<int>>& ans){
        if (index == candidates.size()) return;
        int temp = target;
        for(int i = index; i<candidates.size(); i++){
            if (i>index && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] == target){
                subset.push_back(candidates[i]);
                ans.push_back(subset);
                subset.pop_back();
                continue;
            }
            if(candidates[i] > target){
                continue;
            }
            subset.push_back(candidates[i]);
            sol(candidates, target - candidates[i], i + 1, subset, ans);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        sol(candidates, target, 0, subset, ans);
        // vector<vector<int>>val(ans);
        return ans;
    }
};