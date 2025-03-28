class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<pair<int,int>> bounds (n);
        bounds[0].first = 0;
        bounds[n-1].second = 0;
        int i = 0, j = n-1;
        int lmax = 0, rmax =0;
        while(i<n){
            bounds[i].first =  lmax;
            lmax = max(lmax, height[i++]);
            bounds[j].second = rmax;
            rmax = max(rmax, height[j--]);
        }
        int ans = 0;
        for (int i = 0; i< n; i++){
            int ldepth = ((bounds[i].first - height[i]) > 0) ? (bounds[i].first - height[i]) : 0;
            int rdepth = ((bounds[i].second - height[i]) > 0) ? (bounds[i].second - height[i]) : 0;
            ans += min(ldepth, rdepth);
        }
        return ans;
    }
};