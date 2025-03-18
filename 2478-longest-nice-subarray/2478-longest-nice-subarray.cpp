class Solution {
public:
    int checkifnice(vector<int>& nums, int left, int right){
        int target = nums[right];
        int x = right;
        // cout<<left<<" PLEASE!!!! "<<right<<endl;
        for (int i = left; i < right; i++){
            // cout<<"PLEASE"<<endl;
            if (!((target & nums[i]) == 0)){
                x = i+1;
                // cout<<"HI"<<endl;
            }
        }
        if (x == right && !(nums[right-1] & target)){
            // cout<<"HERE?";
            return -1;
        }
        // cout<<"here";
        return x;
    }
    int longestNiceSubarray(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int lo = 0;
        int curr = 1, ans = 1;
        for (int hi = 1; hi < nums.size(); hi++){
            int newlo = checkifnice(nums, lo, hi);
            // cout<<"NEWLO "<<newlo<<endl;
            if (newlo == -1){
                curr ++;
                // cout<<" YO "<<curr<<endl;
                continue;
            }
            // cout<<newlo<<" "<<hi<<endl;
            // cout<<newlo<<"YOOOOO"<<endl;
            lo = newlo;
            // cout<<ans<<endl;
            ans = max(curr, ans);
            // cout<<"ans"<<ans;
            curr = hi - newlo+1;
        }
        ans = max(curr, ans);
        return ans;
    }
};