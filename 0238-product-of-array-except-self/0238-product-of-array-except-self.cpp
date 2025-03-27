auto _ = cin.tie(nullptr) -> sync_with_stdio(false);
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans (n);
        int curr = 1;
        for(int i = 0; i < n; i++){
            ans[i] = curr;
            curr *= nums[i];
        }
        curr = nums[n-1];
        for (int i = n-2; i>= 0; i--){
            ans[i] *= curr;
            curr *= nums[i];
        }
        return ans;
    }
};