class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cur=0, ans = 0;
        int mid, lo = 0, hi = matrix.size()-1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if (matrix[mid][0] == target) return true;
            // cout<<"CHECK\n";
            if (matrix[mid][0] < target) {
                lo = mid+1;
                cur = mid;
            }
            else hi = mid-1; 
        }
        lo = 0;
        hi = matrix[cur].size()-1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if (matrix[cur][mid] == target) return true;
            if(matrix[cur][mid] < target) {
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }
        return matrix[cur][ans] == target;
    }
};