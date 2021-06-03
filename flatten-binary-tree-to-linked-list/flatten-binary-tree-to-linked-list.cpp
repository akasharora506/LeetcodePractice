
class Solution {
public:
    TreeNode* flat(TreeNode* root){
        if(!root)
            return NULL;
        TreeNode *ls = flat(root->left);
        TreeNode *rs=flat(root->right);
        root->left=0;
        root->right= ls;
        TreeNode* temp=root;
        while(temp&&temp->right)temp=temp->right;
        temp->right=rs;
        return root;
    }
    void flatten(TreeNode* root) {
        flat(root);
    }
};