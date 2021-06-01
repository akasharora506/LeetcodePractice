
class Solution {
public:
    int pathSum(TreeNode* root, int t,bool par=0) {
        if(!root)return 0;
        int ans=0;
        if(t==root->val)ans++;
        ans+=pathSum(root->left,t-root->val,1)+pathSum(root->right,t-root->val,1);
        if(par==0){
            ans+=pathSum(root->left,t,0)+pathSum(root->right,t,0);
        };
        return ans;
    }
};