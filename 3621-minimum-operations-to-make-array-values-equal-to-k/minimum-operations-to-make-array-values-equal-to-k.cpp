class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int num: nums){
            freq[num]++;
        }
        auto itr = freq.begin();
        if (itr-> first < k) return -1;
        if (itr-> first == k) return freq.size()-1;
        return freq.size();
    }
};