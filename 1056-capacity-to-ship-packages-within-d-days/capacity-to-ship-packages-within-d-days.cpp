class Solution {
public:
    int gsize (vector<int>& weights, int lim){
        int cnt = 0, s = 0;
        for (int weight : weights){
            if (weight >lim) return INT_MAX;
            s+= weight;
            if (s > lim){
                s = weight;
                cnt++;
            }
        }
        return cnt+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mid, lo = 1, hi = accumulate(weights.begin(), weights.end(),0);
        if (days == 1) return hi;
        while(lo<hi){
            mid = lo + ((hi-lo)>>1);
            if (gsize(weights, mid)<=days){
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        return lo;
    }
};