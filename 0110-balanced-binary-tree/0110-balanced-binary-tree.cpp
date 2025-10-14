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
private:
    int dfs(TreeNode* root){
        if (!root) return 0;
        int ld = dfs(root->left);
        int rd = dfs(root->right);
        if (ld == -1 || rd == -1) return -1;
        if (abs(ld-rd)>1) return -1;
        return 1+ max(ld,rd);
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans = dfs(root);
        if (ans == -1) return false;
        return true;
    }
};