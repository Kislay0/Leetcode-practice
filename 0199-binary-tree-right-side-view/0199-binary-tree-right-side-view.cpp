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
    int depth = -1, md = -1;
    vector<int>ans;
    void dfs(TreeNode* root){
        if (!root) return;
        depth ++;
        if (depth > md) {
            ans.push_back(root->val);
            md = depth;
        }
        dfs(root->right);
        dfs(root->left);
        depth--;
        return;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        ans = {};
        depth = 0;
        dfs(root);
        return ans;
    }
};