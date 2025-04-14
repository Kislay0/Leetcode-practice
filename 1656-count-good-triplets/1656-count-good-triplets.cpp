auto _ = cin.tie(0)-> sync_with_stdio(false);
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        for (int i = 0; i<arr.size()-2; i++){
            for (int j = i+1; j<arr.size()-1; j++){
                if (abs(arr[j]-arr[i]) <= a){
                    for (int k = j+1; k<arr.size(); k++){
                        if (abs(arr[j]-arr[k]) <= b && abs(arr[k]-arr[i]) <= c) {
                            // cout<<i<<" "<<j<<" "<<k<<endl;
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};