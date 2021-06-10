class Solution {
public:
    vector<int> help(TreeNode* root){
        if(!root)
            return {0,0};
        vector<int> l=help(root->left),r=help(root->right);
        int rob=root->val+l[1]+r[1];
        int notRob=max(l[0]+r[0],max(l[1]+r[1],max(l[1]+r[0],l[0]+r[1])));
        return {rob,notRob};
    }
    int rob(TreeNode* root) {
        vector<int> ans=help(root);
        return max(ans[0],ans[1]);
    }
};