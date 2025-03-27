const auto _= cin.tie(nullptr) -> sync_with_stdio(false);
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        for (int num: nums){
            mp[num]++;
        }
        multimap<int, int, greater<int>> MM;
        for (auto val : mp){
            MM.insert({val.second, val.first});
        }
        int i = 0;
        vector<int> ans;
        for (auto& it : MM){
            i++;
            ans.push_back(it.second);
            if (i== k) break;
        }
        return ans;
        
    }
};