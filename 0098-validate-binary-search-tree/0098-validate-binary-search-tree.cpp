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
    bool isValid(TreeNode* root, long long maxi, long long mini){
        if(!root) return true;
        if(root->val <= mini || root->val >= maxi) {
            // cout<<(root->val <= mini)<<" "<<(root->val >= maxi)<<"\n";
            // cout<<root->val<<" "<<mini<<" "<<maxi;
            return false;
        }
        // if(root->left && root->left->val >= root->val) return false;
        // if(root->right && root->right->val <= root->val) return false;
        return (isValid(root->left, root->val, mini) && isValid(root->right, maxi, root->val));
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, 2147483648, -2147483649);
    }
};