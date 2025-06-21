class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n_sum = (n + rolls.size())*mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (n_sum > 6*n||n_sum < n){
            return {};
        }
        vector<int> result(n,1);
        n_sum -= n;
        for (int& i : result){
            if (n_sum>=5){
                i = 6;
                n_sum -= 5;
            }else if(n_sum > 0){
                i += n_sum;
                n_sum = 0;
                return result;
            }else{
                return result;
            }
        }
        return result;
    }
};