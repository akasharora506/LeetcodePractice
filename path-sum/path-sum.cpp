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
    bool dfs(TreeNode *root, int t,int c=0){
        if(!root)return false;
        if(!root->left&&!root->right)
            return c+root->val==t;
        return dfs(root->left,t,c+root->val)||dfs(root->right,t,c+root->val);
    };
    bool hasPathSum(TreeNode* root, int t) {
        return dfs(root,t);
    }
};