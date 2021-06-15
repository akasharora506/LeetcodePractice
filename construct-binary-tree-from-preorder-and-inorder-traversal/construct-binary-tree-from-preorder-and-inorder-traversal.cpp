
class Solution {
public:
    int indexOf(vector<int> &a,int val){
        for(int i=0;i<a.size();i++){
            if(a[i]==val)return i;
        };
        return -1;
    };
    TreeNode* help(vector<int>& po, vector<int>& io,int ps,int pe,int is,int ie){
        if(ps>pe||is>ie)return NULL;
        TreeNode* root=new TreeNode(po[ps]);
        int i=indexOf(io,po[ps]);
        int n=i-is;
        root->left=help(po,io,ps+1,ps+n,is,is+n-1);
        root->right=help(po,io,ps+n+1,pe,is+n+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return help(preorder,inorder,0,n-1,0,n-1);
    }
};