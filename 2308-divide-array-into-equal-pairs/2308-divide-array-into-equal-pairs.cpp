class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector <int> values (501, 0);
        for(int num : nums) {
            values[num]++;
        }
        for (int value: values){
            if (value%2 == 1) return false;
        }
        return true;
    }
};