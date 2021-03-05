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
    void dfs(TreeNode* root,unordered_map<long long,pair<long long,long long>> &m,int level=0){
        if(!root)
            return;
        m[level].first+=root->val;
        m[level].second++;
        dfs(root->left,m,level+1);
        dfs(root->right,m,level+1);
    };
    vector<double> averageOfLevels(TreeNode* root) {
        unordered_map<long long,pair<long long,long long>> mp;
        dfs(root,mp);
        long long n=mp.size();
        vector<double> ans(n);
        for(auto i: mp){
            ans[i.first]=(double)i.second.first/(double)i.second.second;
        };
        return ans;
    }
};