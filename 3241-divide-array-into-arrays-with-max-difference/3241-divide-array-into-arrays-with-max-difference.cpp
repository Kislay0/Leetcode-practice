class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i< nums.size(); i+=3){
            if (nums[i+2]- nums[i] > k) return {};
            vector<int> temp ={nums[i], nums[i+1], nums[i+2]};
            ans.push_back(temp);
        }
        return ans;
    }
};