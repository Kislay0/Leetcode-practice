class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        for (int j = 1; j<arr.size()-1; j++){
            for (int i = 0; i<j; i++){
                if (abs(arr[i]-arr[j]) <= a){
                    for (int k = j+1; k<arr.size(); k++){
                        if (abs(arr[i]-arr[k]) <= c && abs(arr[k]-arr[j]) <= b) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};