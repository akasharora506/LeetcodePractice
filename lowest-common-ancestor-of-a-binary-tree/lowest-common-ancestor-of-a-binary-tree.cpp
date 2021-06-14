
class Solution {
public:
    bool path(TreeNode* root,vector<TreeNode*> &a,TreeNode* t){
        if(!root)
            return 0;
        a.push_back(root);
        if(root==t){
            return 1;
        };
        if(!path(root->left,a,t)&&!path(root->right,a,t)){
            a.pop_back();
            return 0;
        }
        return 1;
    };
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a,b;
        path(root,a,p);
        path(root,b,q);
        int n=min(a.size(),b.size()),i=0;
        TreeNode* ans=NULL;
        while(i<n&&a[i]==b[i]){
            ans=a[i];
            i++;
        };
        return ans;
    }
};