class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        if (n > maxSum) return -1;
        if (n == maxSum) return 1;
        auto cursum = [&](int x){
            if (x> index){
                if (x> n-index-1) return ((1L*n*(2*x-n+1) + 1L*2*index*(n-index-1))/2.0);
                else return (1L*index* (2*x- index - 3)/2.0 + 1L*x*(x-1)/2.0 + n) ;
            }else{
                if (x> n-index-1) return (1L*(n-index)*(2*x-n+index+1)/2.0 + 1L*x*(x-3)/2.0 + index+1);
                else return (double)(1L*x*(x-2) + n + 1);
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