class Solution {
public:
    long long M=1e9+7;
    void dfs(TreeNode* root,long long &d,long long &sum){
        if(!root||(!root->left&&!root->right))
            return;
        if(root->left)d=max(d,(sum-root->left->val)*root->left->val);
        if(root->right)d=max(d,(sum-root->right->val)*root->right->val);
        dfs(root->left,d,sum);
        dfs(root->right,d,sum);
    }
    long long help(TreeNode* root){
        if(!root)
            return 0;
        root->val=(root->val+help(root->left)+help(root->right))%M;
        return root->val;
    };
    int maxProduct(TreeNode* root) {
        long long d=INT_MIN;
        long long sum=help(root);
        dfs(root,d,sum);
        return d%M;
    }
};