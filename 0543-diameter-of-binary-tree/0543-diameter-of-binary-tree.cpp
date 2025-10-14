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
    int dia;
    int dfs(TreeNode* cur){
        if(!cur) return 0;
        int ld = dfs(cur->left);
        int rd = dfs(cur->right);
        dia = max(dia,ld+rd);
        return 1 + max(ld,rd);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return dia;
    }
};