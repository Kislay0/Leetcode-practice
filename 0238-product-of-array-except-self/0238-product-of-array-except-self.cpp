class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,1),post(n,1);
        for (int i = 1; i<n; i++){
            pre[i] *= nums[i-1]*pre[i-1];
            post[n-i-1] *= nums[n-i]*post[n-i];
        }
        for (int i= 0; i<n; i++){
            pre[i] *= post[i];
        }
        return pre;
    }
};