class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int cnt = 0;
        while(n){
            if(n&1){
                powers.push_back(pow(2,cnt));
            }
            cnt++;
            n/=2;
        }
        vector<int> ans;
        for (const auto& temp : queries){
            int lo = temp[0];
            int hi = temp[1];
            long long val = 1;
            for(int i = lo; i<=hi && i<powers.size(); i++){
                val = (val*powers[i])%(1000000007);
            }
            ans.push_back(val);
        }
        cout<<INT_MAX;
        return ans;
    }
};