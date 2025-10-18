class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums[0] == target) return 0;
        if (nums.back() == target) return nums.size()-1;
        int ans = -1;
        int mid = 0, lo = 0, hi = nums.size()-1;
        if (nums[0] < nums.back()){
            while(lo<=hi){
                mid = hi - (hi-lo+1)/2;
                if (nums[mid] == target) return mid;
                if (nums[mid] < target) lo = mid+1;
                else hi = mid-1;
            }
            return -1;
        }
        if (target>nums[0]){
            while(lo<=hi && lo>=0 && hi < nums.size()){
                mid = hi - (hi-lo+1)/2;
                // cout<<mid;
                // cout<<"IN: "<<lo<<" "<<mid<<" "<<hi<<endl;
                if(nums[mid]==target) return mid;
                if (nums[mid]>target) hi = mid-1;
                else{
                    if(nums[mid]<nums[0]) hi = mid - 1;
                    else lo = mid+1;
                }
            }
            // cout<<lo<<" "<<mid<<" "<<hi<<endl;
            return -1;
        }
        while(lo<=hi && lo>=0 && hi < nums.size()){
            mid = hi - (hi-lo+1)/2;
            // cout<<"IN: "<<lo<<" "<<mid<<" "<<hi<<endl;
            if(nums[mid]==target) return mid;
            if (nums[mid]<target) lo = mid+1;
            else{
                if(nums[mid]>nums.back()) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        // cout<<lo<<" "<<mid<<" "<<hi<<endl;
        return -1;
    }
};