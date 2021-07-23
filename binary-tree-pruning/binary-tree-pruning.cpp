class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return root;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        if(root->val!=1&&!root->right&&!root->left)return NULL;
        return root;
    }
};