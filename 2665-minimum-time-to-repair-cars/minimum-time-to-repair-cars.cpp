class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long mid, lo = 0;
        long long hi = *min_element(ranks.begin(),ranks.end());
        hi *= (long long)cars*cars;

        auto ttlrepair = [&] (long long t){
            long long total = 0;
            for (int rank : ranks){
                total += sqrt(t/rank);
            }
            return total;
        };
        while(lo<hi){
            mid = lo + ((hi - lo)>>1);
            if (ttlrepair(mid)>=cars){
                hi = mid;
            }
            else lo = mid + 1;
        }
        return lo;
    }
};