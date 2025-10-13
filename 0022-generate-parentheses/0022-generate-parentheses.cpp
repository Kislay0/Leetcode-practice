class Solution {
    void helper(int n,vector<string>& ans, string s, int op, int cl){
        if (cl >op || op>n) return;
        if (cl == n) {
            ans.push_back(s);
            return;
        }
        if (op == cl) helper(n, ans, s +"(" , op+1, cl);
        else {
            helper(n, ans, s +"(" , op+1, cl);
            helper(n, ans, s +")" , op, cl+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, ans, "", 0, 0);
        return ans;
    }
};