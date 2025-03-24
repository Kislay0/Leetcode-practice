const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        vector<vector<int>> mergedmeet;
        for (const auto& meet: meetings){
            if(mergedmeet.empty() || meet[0]>mergedmeet.back()[1]){
                mergedmeet.push_back(meet);
            }
            else {
                mergedmeet.back()[1] = max(mergedmeet.back()[1], meet[1]);
            }
        }

        int ans = mergedmeet[0][0] - 1;
        for (int i = 0; i< mergedmeet.size()-1; i++){
            ans += mergedmeet[i+1][0] - mergedmeet[i].back() -1;
        }
        ans += days - mergedmeet.back().back();
        return ans;
    }
};