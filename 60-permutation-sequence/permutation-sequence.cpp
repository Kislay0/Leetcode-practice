class Solution {
public:
    int greatest_lower (unordered_map<int, int>fact, int a){
        int lo = 1, hi = 9;
        int mid, ans = 1;
        while(hi >= lo){
            mid = (lo+hi)>>1;
            if (fact[mid] == a) return mid;
            if (fact[mid] > a){
                hi = mid-1;
            }
            else {
            ans = mid;
            lo = mid+1;
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
    string getPermutation(int n, int k) {
        unordered_map <int,int> fact = {
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
        vector<int> available;
        for (int i = 1; i<= n; i++){
            available.push_back(i);
        }
        //
        string ans = "";
        int arranged, left = greatest_lower(fact, k);
        // cout<<left<<endl;
        if (k-fact[left] == 0){
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
        // cout<<ans<<endl;
        // cout<< "arranged: " << arranged << endl;
        // cout<<"left: "<<left<<endl;

        while(k>=0){
            int cnt = 0;
            left--;
            // cout<<"K "<<k<<" left "<<left<<endl;
            if (left == 0) return ans + to_string(available[0]);
            while (k>fact[left]){
                cnt++;
                k -= fact[left];
                // cout<<"K "<<k<<" cnt "<<cnt<<endl;
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