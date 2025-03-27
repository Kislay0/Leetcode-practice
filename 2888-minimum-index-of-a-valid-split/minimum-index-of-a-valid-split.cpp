auto _ = cin.tie(nullptr)->sync_with_stdio(false);
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dif = -1;
        int major = nums[0];
        for (int num : nums){
            if (num == major) dif++;
            else dif--;
            if (dif<0) {
                major = num;
                dif = 0;
            }
        }
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i< n; i++){
            if (nums[i] == major) cnt++;
        }
        int val = 0;
        for (int i = 0; i< n; i++){
            if (nums[i] == major) val++;
            if ((val > (i+1)/2) && (cnt-val > (n-i-1)/2)) return i;
        }
        return -1;

    }
};