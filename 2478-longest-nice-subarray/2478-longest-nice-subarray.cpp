class Solution {
public:
    int checkifnice(vector<int>& nums, int left, int right){
        int target = nums[right];
        int x = right;
        for (int i = left; i < right; i++){
            if (target & nums[i]){
                x = i+1;
            }
        }
        if (x == right && !(nums[right-1] & target)){
            return -1;
        }
        return x;
    }
    int longestNiceSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int lo = 0;
        int curr = 1, ans = 1;
        for (int hi = 1; hi < nums.size(); hi++){
            int newlo = checkifnice(nums, lo, hi);
            if (newlo == -1){
                curr ++;
                continue;
            }
            lo = newlo;
            ans = max(curr, ans);
            curr = hi - newlo + 1;
        }
        ans = max(curr, ans);
        return ans;
    }
};