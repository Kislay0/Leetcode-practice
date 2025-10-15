class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0]<nums.back()) return nums[0];
        int ans = 0, n = nums.size();
        int lo = 0, hi= n-1;
        while(lo<hi){
            int mid = (hi + lo)/2;
            // cout<<mid<<" "<<lo<<" "<<hi<<"\n";
            // cout<<nums[lo]<<" "<<nums[mid]<<" "<<nums[hi]<<"\n";
            if (nums[lo]<nums[hi]) return nums[lo];
            if (nums[mid]<nums[lo]) {
                hi = mid;
                ans = mid;
            }
            else{
                // cout<<"Check\n";
                lo = mid+1;
            }
        }
        return nums[hi];
    }
};