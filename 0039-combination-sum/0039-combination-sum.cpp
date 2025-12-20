class Solution {
private:
    void sol(vector<int>& candidates, int target, int index, vector<int> subset, int curr, vector<vector<int>>& ans){
        int temp = curr;
        vector<int>tempset = subset;
        for (int i = index; i< candidates.size(); i++){
            curr = temp;
            subset = tempset;
            if (curr + candidates[i] > target) continue;
            if (curr + candidates[i] == target) {
                subset.push_back(candidates[i]);
                ans.push_back(subset);
                continue;
            }
            subset.push_back(candidates[i]);
            curr+= candidates[i];
            sol(candidates, target, i, subset, curr, ans);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> ans;
        sol(candidates, target, 0, subset, 0, ans);
        return ans;
    }
};