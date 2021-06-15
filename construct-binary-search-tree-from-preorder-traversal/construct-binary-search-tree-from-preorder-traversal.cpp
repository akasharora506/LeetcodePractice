class Solution {
public:
    TreeNode* help(vector<int>& p,int start,int end){
        if(start>end)return NULL;
        TreeNode* root=new TreeNode(p[start]);
        if(start==end)return root;
        int curr=p[start];
        int i=start+1;
        while(i<p.size()&&p[i]<curr)i++;
        root->left=help(p,start+1,i-1);
        root->right=help(p,i,end);
        return root;
    };
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return help(preorder,0,preorder.size()-1);
    }
};