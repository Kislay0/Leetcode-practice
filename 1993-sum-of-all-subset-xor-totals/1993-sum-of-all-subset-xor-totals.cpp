class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        summ(nums, sum, 0, 0);
        return sum;
    }
    void summ (vector<int>& nums, int& sum, int i, int x){
        if (i == nums.size()-1) {
            sum += x^nums.back();
            return;
        }
        summ(nums,sum, i+1, x);
        x ^= nums[i];
        sum += x;
        summ(nums,sum, i+1, x);
        return;
    }
};