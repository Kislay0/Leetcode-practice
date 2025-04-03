class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 3) return (((nums[0]- 1LL*nums[1])* nums[2]) >0) ? ((nums[0]- 1LL*nums[1])* nums[2]) : 0;
        vector<int> dif(n-1);
        dif[0] = 0;
        int maxi = nums[0];
        for (int i = 1; i<n-1; i++){
            dif[i] = max (dif[i-1], maxi - nums[i]);
            maxi = max(maxi, nums[i]);
        }
        // for(auto x: dif){
        //     cout<<x<<" ";
        // }
        cout<<endl;
        long long ans = 0;
        for (int i = 2; i<n; i++){
            ans = max(ans, 1LL*nums[i]*dif[i-1]);
        }

        return ans;

    }
};