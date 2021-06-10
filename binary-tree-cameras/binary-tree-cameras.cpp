
class Solution {
public:
    string help(TreeNode* root,int &camera) {
        if(!root)
            return "m_wc";
        string l=help(root->left,camera),r=help(root->right,camera);
        if(l=="m_wc"&&r=="m_wc")
            return "un_wc";
        if(l=="un_wc"||r=="un_wc"){
            camera++;
            return "m_c";
        };
        return "m_wc";
        
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
        string s=help(root,ans);
        return ans+(s=="un_wc");
    }
};