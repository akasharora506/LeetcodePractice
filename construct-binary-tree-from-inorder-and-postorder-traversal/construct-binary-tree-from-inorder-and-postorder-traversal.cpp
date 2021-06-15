class Solution {
public:
    int indexOf(vector<int> &a,int val){
        for(int i=0;i<a.size();i++){
            if(a[i]==val)return i;
        };
        return -1;
    }
    TreeNode* help(vector<int> &io,vector<int> &po,int is,int ie,int ps,int pe){
        if(ps>pe||is>ie)
            return NULL;
        TreeNode* root=new TreeNode(po[pe]);
        int i=indexOf(io,po[pe]);
        int n=i-is;
        root->left=help(io,po,is,is+n-1,ps,ps+n-1);
        root->right=help(io,po,is+n+1,ie,ps+n,pe-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return help(inorder,postorder,0,n-1,0,n-1);
    }
};