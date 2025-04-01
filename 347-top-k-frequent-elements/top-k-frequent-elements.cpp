const auto _= cin.tie(nullptr) -> sync_with_stdio(false);
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return nums;
        }
        unordered_map <int, int> mp;
        for (int num: nums){
            mp[num]++;
        }
        auto comp = [&mp](int n1, int n2) { return mp[n1] > mp[n2];};
        priority_queue<int, vector<int>, decltype(comp)> heap (comp);

        for (auto p: mp){
            heap.push(p.first);
            if (heap.size()>k) heap.pop();
        }

        vector<int> ans(k);
        for(int i = 0; i<k; i++){
            ans[i] = heap.top();
            heap.pop();
        }
        return ans;
    }
};