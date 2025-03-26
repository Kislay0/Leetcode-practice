class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        for(auto row: grid){
            for (int element: row){
                values.push_back(element);
            }
        }
        nth_element(values.begin(), values.begin()+ values.size()/2, values.end());
        int median = values[values.size()/2];
        int ans = 0;

        for (int val: values){
            if (val % x != median % x) return -1;

            ans += abs(val - median)/x;
        }
        return ans;
    }
};