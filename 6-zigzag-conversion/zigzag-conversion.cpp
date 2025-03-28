class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans = "";
        int i = 0;
        while (i < s.size()){
            // cout<<"HERE"<<endl;
            ans += s[i];
            i += (numRows - 1)<<1;
        }

        int x = (numRows - 2)<< 1;
        i = 1;
        while (i < numRows -1){
            // cout<<"HERE"<<endl;
            for (int j = i; j< s.size(); j+= (numRows - 1)<<1){
                ans += s[j];
                if (j + x <s.size()) ans += s[j+x];
            }

            x -= 2;
            i++;
        }
        i = numRows-1;
        while (i< s.size()){
            ans += s[i];
            i += (numRows - 1)<<1;
        }

        return ans;
    }
};