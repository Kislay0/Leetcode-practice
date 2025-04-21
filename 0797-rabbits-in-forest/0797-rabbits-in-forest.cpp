class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> rabbits;
        int cnt=0;
        for (int ans: answers){
            rabbits[ans]++;
            if (rabbits[ans]>ans) {
                cnt += rabbits[ans];
                rabbits[ans] = 0;
            }
        }
        for (auto rab: rabbits){
            if (rab.second != 0) cnt+= rab.first + 1;
        }
        return cnt;
    }
};