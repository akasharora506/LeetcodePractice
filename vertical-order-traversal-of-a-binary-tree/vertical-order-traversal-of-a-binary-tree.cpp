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
    void dfs(map<int,vector<pair<int,int>>> &m,TreeNode* root,int cr=0,int cc=0){
        if(!root)
            return;
        m[cc].push_back({cr,root->val});
        dfs(m,root->left,cr+1,cc-1);
        dfs(m,root->right,cr+1,cc+1);
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> m;
        dfs(m,root);
        for(auto i:m){
            auto c=i.second;
            sort(c.begin(),c.end());
            vector<int> p;
            for(auto j:c)p.push_back(j.second);
            ans.push_back(p);
        };
        return ans;
    }
};