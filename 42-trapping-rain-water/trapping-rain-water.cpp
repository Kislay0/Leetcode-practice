auto _ = cin.tie(nullptr) -> sync_with_stdio(false);
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        int gmax = 0;
        int temp = 0;
        for (int i = 0; i<n; i++){
            if (height[i]>=temp){
                temp = height[i];
                gmax = i;
            }
        }
        // cout<<"gmax: "<<gmax<<endl;
        int lmax = 0;
        int ans = 0;
        for (int i = 0; i<gmax; i++){
            if (lmax > height[i]) {
                ans += lmax - height[i];
                // cout<<i<<" val: "<<height[i]<<" 1: "<<lmax - height[i]<<endl;
            }
            else lmax = height[i];
        }
        lmax = 0;
        for (int i = n - 1; i > gmax; i--){
            if (lmax > height[i]) {
                ans += lmax - height[i];
                // cout<<i<<" val: "<<height[i]<<" 1: "<<lmax - height[i]<<endl;
            }
            else lmax = height[i];
        }
        return ans;
    }
};