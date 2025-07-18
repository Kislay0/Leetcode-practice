class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<string> seen;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i< nums.size()-2; i++){
            int j = i+1, k = nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k] == 0){
                    if (seen.find(to_string(nums[i]) + " " +to_string(nums[j]) + " " +to_string(nums[k])) == seen.end()){
                        ans.push_back({nums[i],nums[j],nums[k]});
                        seen.insert(to_string(nums[i]) + " " +to_string(nums[j]) + " " +to_string(nums[k]));
                    }else {
                        j++;
                        k--;
                    }
                }else if(nums[i]+nums[j]+nums[k] > 0) k--;
                else j++;
            }
        }
        return ans;
    }
};