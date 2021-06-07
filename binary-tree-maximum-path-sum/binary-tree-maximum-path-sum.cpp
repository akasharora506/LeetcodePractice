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
    void help(TreeNode* root,int &left_max,int curr=0){
        if(!root)
            return;
        curr+=root->val;
        left_max=max(left_max,curr);
        help(root->left,left_max,curr);
        help(root->right,left_max,curr);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return INT_MIN;
        int lm=0,rm=0;
        help(root->left,lm);
        help(root->right,rm);
        int other=max(maxPathSum(root->left),maxPathSum(root->right));
        return max(root->val+lm+rm,other);
    }
};