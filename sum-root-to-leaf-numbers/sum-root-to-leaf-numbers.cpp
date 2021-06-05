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
    void help(TreeNode* root,unordered_multiset<string> &v,string s=""){
        if(!root)
            return;
        if(!root->left&&!root->right){
            v.insert(s+to_string(root->val));
            return;
        };
        help(root->left,v,s+to_string(root->val));
        help(root->right,v,s+to_string(root->val));
    }
    int sumNumbers(TreeNode* root) {
        unordered_multiset<string> v;
        help(root,v);
        int ans=0;
        for(auto i:v){
            ans+=stoi(i);
        };
        return ans;
    }
};