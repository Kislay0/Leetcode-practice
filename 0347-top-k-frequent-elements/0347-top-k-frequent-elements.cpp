const auto _= cin.tie(nullptr) -> sync_with_stdio(false);
class Solution {
private:
    vector<int> unique;
    unordered_map<int, int> mp;
public:
    int partition(int lo, int hi, int pivot){

        swap(unique[hi], unique[pivot]);
        int pivot_freq = mp[unique[hi]];
        int j = lo;
        for (int i = lo; i<hi; i++){
            if (mp[unique[i]] < pivot_freq) swap(unique[i], unique[j]), j++;
        }
        swap (unique[hi], unique[j]);
        return j;
        
    }

    void Quickselect(int lo, int hi, int kth){
        if (lo == hi) return;

        int pivot = lo + rand() % (hi - lo + 1);
        pivot = partition(lo, hi, pivot);
        if (pivot == kth) return;
        if (pivot > kth) {
            Quickselect(lo, pivot -1, kth);
        }
        else {
            Quickselect(pivot+1, hi, kth);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return nums;
        }
        for (int  num: nums){
            mp[num]++;
        }
        int n = mp.size();
        for (auto p : mp){
            unique.push_back(p.first);
        }
        Quickselect(0, n-1, n - k);

        vector<int> ans(unique.begin()+ n - k, unique.end());
        return ans;
        
    }
};