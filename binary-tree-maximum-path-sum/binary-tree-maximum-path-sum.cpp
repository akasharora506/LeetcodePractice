
class Solution {
public:
    int ans=INT_MIN;
    int help(TreeNode* root) {
        if(!root)
            return 0;
        int l=max(help(root->left),0);
        int r=max(help(root->right),0);
        ans=max(ans,root->val+r+l);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root){
        if(!root)
            return 0;
        help(root);
        return ans;
    }
};