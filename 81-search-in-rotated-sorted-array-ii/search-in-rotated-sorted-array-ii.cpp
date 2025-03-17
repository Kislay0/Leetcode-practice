class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mid, lo = 0, hi = nums.size()-1;
        while(lo<=hi){
            mid = lo + ((hi - lo)>>1);
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[lo]) {
                cout<<lo<<endl;
                lo++;
                continue;
            }
            if (nums[mid] > nums[lo]){
                if(nums[mid] > target && target >= nums[lo]) {
                    hi = mid;
                }
                else lo = mid + 1;
            }else{
                if (nums[mid] < target && target <= nums[hi]){
                    lo = mid + 1;
                }
                else hi = mid;
            }
        }
        return false;
    }
};