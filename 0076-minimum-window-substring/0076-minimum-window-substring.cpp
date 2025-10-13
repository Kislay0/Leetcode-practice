class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size(), m = s.size( );
        if (m < n) return "";
        int high = 0, match = 0;
        unordered_map<int,int>tvals;
        vector<int>svals(58,0);
        for (char ch : t){
            tvals[ch-'A']++;
        }
        int goal = tvals.size();
        for (int i = 0; i< n; i++){
            svals[s[i]-'A']++;
        }
        for (int i = 0; i<58; i++){
            if (tvals.find(i) != tvals.end() && tvals.at(i) < svals[i]) high++;
            if (tvals.find(i) != tvals.end() && tvals.at(i) == svals[i]) {
                match++;
                // cout<<i+'A'<<" ";
            }
        }
        // cout<<endl;
        if (match == goal) return s.substr(0,n);
        int lo = 0, mini = INT_MAX, bestlo = -1;
        // cout<<high<<" "<<match<<"\n";
        for (int i = n; i < m; i++){
            // cout<<i<<" "<<s[i]<<"\n";
            svals[s[i]-'A']++;
            if (tvals.find(s[i] - 'A') != tvals.end() && tvals.at(s[i] - 'A') == svals[s[i] - 'A']) {
                match++;
            }
            else if(tvals.find(s[i] - 'A') != tvals.end() && tvals.at(s[i] - 'A') == svals[s[i] - 'A'] - 1) {
                high++;
                match--;
            }
            // cout<<s[i]<<" "<<high<<" "<<match<<"\n";
            while(high + match == goal){
                // cout<<"IN: "<<s[i]<<" "<<high<<" "<<s[lo]<<" "<<match<<"\n";
                int cur = i-lo +1;
                if (cur == n) return s.substr(lo, n);
                if (cur < mini){
                    bestlo = lo;
                    mini = cur;
                }
                if (tvals.find(s[lo] - 'A') != tvals.end() && tvals.at(s[lo] - 'A') == svals[s[lo] - 'A']) match--;
                else if (tvals.find(s[lo] - 'A') != tvals.end() && tvals.at(s[lo] - 'A') == svals[s[lo] - 'A'] - 1) {
                    high--;
                    match++;
                }
                svals[s[lo]-'A']--;
                lo++;
            }
        }
        if (bestlo == -1) return "";
        else return s.substr(bestlo,mini);
    }
};
// "qsvczwsslkhwg"
// "cgklvwl dzpfdqsapogwvjtvbzahjnsejwnuhmomlfsrvmrnczjzjevkdvroiluthhpqtffhlzyglrvorgnalk"