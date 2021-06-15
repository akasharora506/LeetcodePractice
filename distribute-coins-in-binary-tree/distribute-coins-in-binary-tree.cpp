class Solution {
public:
    int help(TreeNode* root,int &ans) {
        if(!root)
            return 0;
        int l=help(root->left,ans);
        int r=help(root->right,ans);
        ans+=abs(l)+abs(r);
        return l+r+root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        int ans=0;
        help(root,ans);
        return ans;
    }
};