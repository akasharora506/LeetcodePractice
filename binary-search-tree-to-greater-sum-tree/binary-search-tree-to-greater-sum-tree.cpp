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
    int ans=0;
    void help(TreeNode* root) {
        if(!root)
            return;
        help(root->right);
        root->val+=ans;
        ans=root->val;
        help(root->left);
    }
    TreeNode* bstToGst(TreeNode* root){
        if(!root)
            return NULL;
        TreeNode* temp=root;
        help(temp);
        return root;
    }
};