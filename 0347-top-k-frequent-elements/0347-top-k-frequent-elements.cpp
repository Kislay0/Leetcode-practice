const auto _= cin.tie(nullptr) -> sync_with_stdio(false);
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        for (int num: nums){
            mp[num]++;
        }
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        for (auto val : mp){
            freq[val.second].push_back(val.first);
        }
        vector <int> ans;
        for (int i = freq.size()-1; i>= 0; i--){
            for (auto x: freq[i]) {
                ans.push_back(x);
                if(--k == 0) return ans;
            }
        }
        return ans;
        
        
    }
};