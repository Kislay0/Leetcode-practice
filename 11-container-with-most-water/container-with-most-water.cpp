class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int i =0, j = height.size()-1;
        while(i<j){
            int arr;
            if (height[i]>height[j]){
                arr = height[j]*(j-i);
                j--;
            }else{
                arr = height[i]*(j-i);
                i++;
            }
            maxarea = max(arr, maxarea);
        }
        return maxarea;
    }
};