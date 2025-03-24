class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        // auto it = meetings.begin();
        // int ans = meetings[0][0] - 1;
        // while (it < meetings.end()-1){
        //     auto next_it = it+1;
        //     if ((*it).back() >= (*next_it)[0]){
        //         if ((*it).back() >= (*next_it).back()){
        //             meetings.erase(it+1);
        //             continue;
        //         }
        //         else {
        //             (*it).back() = (*next_it).back();
        //             meetings.erase(it+1);
        //             continue;
        //         }
        //     }
        //     else{
        //         ans += (*next_it)[0] - (*it).back() -1;
        //     }
        //     it++;
        // }
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