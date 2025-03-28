class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;
        int n = s.size();
        numRows--;
        string ans (n, '\0');
        int index = 0;
        int i = 0;
        while (i < n){
            ans[index++] = s[i];
            i += (numRows)<<1;
        }

        int x = (numRows - 1)<< 1;
        i = 1;
        while (i < numRows){
            for (int j = i; j< n; j += (numRows)<<1){
                ans[index++] = s[j];
                if (j + x <n) ans[index++] = s[j+x];
            }
            x -= 2;
            i++;
        }
        i = numRows;
        while (i< n){
            ans[index++] = s[i];
            i += (numRows)<<1;
        }

        return ans;
    }
};