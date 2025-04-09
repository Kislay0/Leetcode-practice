class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> freq;
        for (int num: nums){
            freq.insert(num);
        }
        int itr = *freq.begin();
        if (itr < k) return -1;
        if (itr == k) return freq.size()-1;
        return freq.size();
    }
};