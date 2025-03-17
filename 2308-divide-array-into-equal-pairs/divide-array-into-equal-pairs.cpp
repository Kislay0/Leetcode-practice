class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> values;
        for(int num : nums) {
            values[num]++;
        }
        for (auto value: values){
            if (value.second % 2 == 1) return false;
        }
        return true;
    }
};