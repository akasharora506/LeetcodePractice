class Solution {
public:
    int help(TreeNode* root,int &ans){
        if(!root)
            return 0;
        int l=help(root->left,ans);
        int r=help(root->right,ans);
        ans+=abs(l)+abs(r);
        return root->val+l+r-1;
    }
    int distributeCoins(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        help(root,ans);
        return ans;
    }
};