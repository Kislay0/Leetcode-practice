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
    void dfs(TreeNode* root, int k, int& pos, int& ans){
        if (!root) return;
        if (pos>k) return;
        if (!root->left){
            pos++;
            if (pos == k) {
                ans = root->val;
                return;
            }
        }else{
            dfs(root->left, k, pos, ans);
            pos++;
        }
        if (pos == k){
            ans = root->val;
            return;
        }
        dfs(root->right, k, pos, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int pos = 0;
        dfs(root, k, pos, ans);
        return ans;
    }
};