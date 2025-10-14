class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> ans(n);
        for (int i = n-1; i>=0; i--){
            if (st.empty()) {
                ans[i] = 0;
                pair<int,int> val;
                val.first = temperatures[i];
                val.second = i;
                st.push(val);
            }
            else{
                while(!st.empty() && st.top().first<=temperatures[i]){
                    st.pop();
                }
                if (st.empty()) ans[i] = 0;
                else ans[i] = st.top().second - i;
                st.push({temperatures[i], i});
            }
        }
        return ans;
    }
};