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
    int dfs(TreeNode* root, int maxi){
        if (!root) return 0;
        int l, r;
        if (root->val >= maxi) {
            l = dfs(root->left, root->val);
            r = dfs(root->right, root->val);
            return 1+l+r;
        }
        l = dfs(root->left, maxi);
        r = dfs(root->right, maxi);
        return l+r;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};