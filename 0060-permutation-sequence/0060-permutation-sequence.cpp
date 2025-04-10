class Solution {
private:
static const unordered_map <int,int> fact;
int greatest_lower (int a){
    int lo = 1, hi = 9;
    int mid, ans = 1;
    while(hi >= lo){
        mid = (lo+hi)>>1;
        if (fact.at(mid) == a) return mid;
        if (fact.at(mid) > a){
            hi = mid-1;
        }
        else {
        ans = mid;
        lo = mid+1;
        }
    }
    return ans;
}
public:
    string getPermutation(int n, int k) {
        vector<int> available;
        for (int i = 1; i<= n; i++){
            available.push_back(i);
        }

        string ans = "";
        int arranged, left = greatest_lower(k);
        if (k-fact.at(left) == 0){
            arranged = n - left;
            for (int i = 1; i <= arranged; i++){
                available.erase(available.begin());
                ans += to_string(i);
            }
        }else{
            left++;
            arranged = n - left;
            for (int i = 1; i <= arranged; i++){
                available.erase(available.begin());
                ans += to_string(i);
            }
        }
        while(k>=0){
            int cnt = 0;
            left--;
            if (left == 0) return ans + to_string(available[0]);
            while (k>fact.at(left)){
                cnt++;
                k -= fact.at(left);
            }
            ans += to_string(available[cnt]);
            available.erase(available.begin() + cnt);
            if (k== 0) {
                ans += to_string(available[cnt]);
                break;
            }
        }
        return ans;

    }
};

const unordered_map<int, int> Solution::fact = {
    {1, 1},
    {2, 2},
    {3, 6},
    {4, 24},
    {5, 120},
    {6, 720},
    {7, 5040},
    {8, 40320},
    {9, 362880}
};