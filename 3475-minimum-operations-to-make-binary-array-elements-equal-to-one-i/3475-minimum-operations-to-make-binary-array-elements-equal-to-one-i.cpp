class Solution {
public:
    int minOperations(vector<int>& nums) {
        auto flip = [&] (int left){
            for (int i = left; i <= left + 2; i++){
                nums[i] ^= 1;
            }
        };
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i <= n - 3; i++){
            if (nums[i] == 0){
                flip(i);
                cnt++;
            }
        }
        if (nums.back() == 1 & nums[n-2] == 1 ) return cnt;
        return -1;
    }
};