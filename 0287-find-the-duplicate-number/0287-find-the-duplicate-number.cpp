class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do{
            // cout<<slow<<" "<<fast<<endl;
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while( slow!= fast);
        cout<<fast<<endl;
        slow = 0;
        while(slow!= fast){
            // cout<<slow<<" "<<fast<<endl;
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

