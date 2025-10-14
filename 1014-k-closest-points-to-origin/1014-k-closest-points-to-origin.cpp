class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pnts;
        vector<vector<int>> ans;
        for(vector<int> p: points){
            double d = sqrt(p[0]*p[0] + p[1]*p[1]);
            pnts.push({d, p});
            if (pnts.size()>k) pnts.pop();
        }
        for (int i = 0; i<k; i++){
            ans.push_back(pnts.top().second); pnts.pop();
        }
        return ans;
    }
};