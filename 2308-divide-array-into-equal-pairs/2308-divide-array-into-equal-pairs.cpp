class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> values = {};
        for(int num : nums) {
            if (values.find(num) == values.end()) values.insert(num);
            else values.erase(num);
        }
        if (values.size() == 0) return true;
        return false;
    }
};