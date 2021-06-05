class Solution {
public:
    TreeNode* find(TreeNode* root,int x){
        if(!root||root->val==x)
            return root;
        TreeNode* a=find(root->left,x),*b=find(root->right,x);
        return a?a:b;
    };
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        return 1+dfs(root->left)+dfs(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* node=find(root,x);
        int countLS=dfs(node->left),countRS=dfs(node->right),countPar=n-dfs(node);
        return countLS>n/2||countRS>n/2||countPar>n/2;
    }
};