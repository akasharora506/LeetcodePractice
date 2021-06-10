class Solution {
public:
    unordered_map<TreeNode*,int> t,f;
    int help(TreeNode* root,bool rob){
        if(!root){
            if(rob)t[root]=0;
            else f[root]=0;
            return 0;
        };
        int a=f.count(root->left)?f[root->left]:help(root->left,0);
        int b=f.count(root->right)?f[root->right]:help(root->right,0);
        if(rob)return t[root]=root->val+a+b;
        int c=t.count(root->left)?t[root->left]:help(root->left,1);
        int d=t.count(root->right)?t[root->right]:help(root->right,1);
        return f[root]=max(a+b,max(a+d,max(b+c,c+d)));
    };
    int rob(TreeNode* root) {
        help(root,1);
        help(root,0);
     return max(t[root],f[root]);   
    }
};