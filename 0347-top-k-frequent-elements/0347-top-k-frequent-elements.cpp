class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for (int num: nums) mp[num]++;
        auto cmp = [](pair<int,int> a, pair<int, int> b){
            return a.first>b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> heap(cmp);
        for (auto p : mp){
            heap.push({p.second,p.first});
            if(heap.size()>k) heap.pop();
        }
        vector<int> ans;
        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};