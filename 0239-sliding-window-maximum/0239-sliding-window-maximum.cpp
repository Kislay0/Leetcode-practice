class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int>heap;
        vector<int> ans;
        unordered_map<int,int> seen;
        int cur = INT_MIN;
        for(int i= 0; i<k; i++){
            cur = max(cur, nums[i]);
            seen[nums[i]]++;
            heap.push(nums[i]);
        }
        // heap.push(cur);
        ans.push_back(cur);
        // for (int i = k; i<nums.size() && i<2*k; i++){
        //     heap.push(nums[i]);
        //     ans.push_back(heap.top());
        //     seen[nums[i]]++;
        // }
        for (int i = k; i<nums.size(); i++){
            heap.push(nums[i]);
            seen[nums[i]]++;
            // heap.pop(nums[i-k]);
            seen[nums[i-k]]--;
            while(!seen[heap.top()]){
                // cout<<heap.top();
                heap.pop();
            }
            ans.push_back(heap.top());
        }
        return ans;
    }
};