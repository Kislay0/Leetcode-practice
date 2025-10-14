/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        int h = 0;
        queue<TreeNode*> cur, next;
        vector<vector<int>>ans;
        cur.push(root);
        while(!cur.empty()){
            // queue<TreeNode*> next;
            ans.push_back({});
            while(!cur.empty()){
                TreeNode* a = cur.front(); cur.pop();
                ans[h].push_back(a->val);
                if (a->left) next.push(a->left);
                if (a->right) next.push(a->right);
            }
            cur = next;
            next = {};
            h++;
        }
        return ans;
        
    }
};