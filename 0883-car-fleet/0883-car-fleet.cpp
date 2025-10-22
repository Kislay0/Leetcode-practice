class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int, double>> pq;
        int ans = 0;
        for (int i = 0; i<position.size(); i++){
            double t = 1.0*(target - position[i])/speed[i];
            pq.push({position[i], t});
        }
        double cur = DBL_MIN;
        while (!pq.empty()){
            int pos = pq.top().first;
            double time = pq.top().second;
            pq.pop();
            if (time > cur){
                ans++;
                cur = time;
            }
        }
        return ans;
    }
};