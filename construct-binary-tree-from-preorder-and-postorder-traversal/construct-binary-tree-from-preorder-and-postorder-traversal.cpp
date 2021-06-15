class Solution {
public:
    int indexOf(vector<int> &a,int val){
        for(int i=0;i<a.size();i++){
            if(a[i]==val)return i;
        };
        return -1;
    }
    TreeNode* help(vector<int>& pr,vector<int> &po,int a,int b,int p,int q){
        if(a>pr.size()||p>q)return NULL;
        TreeNode *root=new TreeNode(pr[a]);
        if(a==b||p==q)return root;
        int l=pr[a+1];
        int r=po[q-1];
        int lin=indexOf(po,l);
        int rin=indexOf(pr,r);
        root->left=help(pr,po,a+1,rin-1,p,lin);
        if(l!=r)root->right=help(pr,po,rin,b,lin+1,q-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        return help(pre,post,0,n-1,0,n-1);
    }
};