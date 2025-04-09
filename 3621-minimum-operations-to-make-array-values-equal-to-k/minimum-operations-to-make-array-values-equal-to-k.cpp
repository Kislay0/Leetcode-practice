class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> freq;
        int lo = INT_MAX;
        for (int num: nums){
            freq.insert(num);
            lo = min(lo, num);
        }
        if (lo < k) return -1;
        if (lo == k) return freq.size()-1;
        return freq.size();
    }
};