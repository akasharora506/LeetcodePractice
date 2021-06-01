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
    void dfs(vector<vector<int>> &ans,vector<int> &curr,TreeNode *root,int t){
        if(!root)
            return;
        if(!root->left&&!root->right){
            if(t==root->val){
                curr.push_back(root->val);
                ans.push_back(curr);
                curr.pop_back();
            };
            return;
        };
        curr.push_back(root->val);
        dfs(ans,curr,root->left,t-root->val);
        dfs(ans,curr,root->right,t-root->val);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(ans,curr,root,t);
        return ans;
    }
};