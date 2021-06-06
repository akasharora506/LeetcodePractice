class Solution {
public:
    int ans=0;
    int longestZigZag(TreeNode* root,int par=-1){
        if(!root)
            return 0;
        int l=longestZigZag(root->left,0);
        int r=longestZigZag(root->right,1);
        ans=max(ans,1+max(l,r));
        if(par==0){
            return 1+r;
        }else if(par==1){
            return 1+l;
        };
        return ans-1;
    }

};