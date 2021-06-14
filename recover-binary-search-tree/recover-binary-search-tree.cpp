/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev=NULL;
    TreeNode* first=NULL,*last=NULL;
    void isBST(TreeNode* root){
        if(!root)
            return;
        isBST(root->left);
        if(prev && prev->val>root->val){
            if(!first)first=prev;
            last=root;
        };
        prev=root;
        isBST(root->right);
}
    void recoverTree(TreeNode* root) {
        isBST(root);
        swap(first->val,last->val);
    }
};