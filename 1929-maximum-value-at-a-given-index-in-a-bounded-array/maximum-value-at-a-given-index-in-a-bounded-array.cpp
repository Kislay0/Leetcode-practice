class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        if (n == maxSum) return 1;
        auto cursum = [&](int x){
            if (x> index){
                if (x> n-index-1) return ((1LL*n*(2*x-n+1) + 1LL*2*index*(n-index-1))/2.0);
                else return (1LL*index* (2*x- index - 1)/2.0 + 1LL*x*(x+1)/2.0 + n-index-x) ;
            }else{
                if (x> n-index-1) return (1LL*(n-index)*(2*x-n+index+1)/2.0 + 1LL*x*(x-1)/2.0 + index-x+1);
                else return (double)(1LL*x*(x+1) + n-1LL*3*x+1);
            }
        };
        int lo = 2, hi = maxSum;
        int ans=lo;
        while(lo<=hi){
            int mid = lo + ((hi - lo)>>1);
            if(cursum(mid)>maxSum){
                hi = mid -1;
            }
            else{
                lo = mid +1;
                ans = mid;
            }
        }
        return ans;
    }
};