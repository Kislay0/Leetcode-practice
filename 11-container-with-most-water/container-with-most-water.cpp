class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0, j = height.size()-1;
        while (i<j){
            if (height[i]<height[j]){
                int water = height[i]*(j-i);
                i++;
                ans = max(water, ans);
            }else{
                int water = height[j]*(j-i);
                j--;
                ans = max(water, ans);
            }
        }
        return ans;
    }
};