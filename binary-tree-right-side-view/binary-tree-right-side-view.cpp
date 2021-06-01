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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
       deque<TreeNode *> q;
       q.push_back(root);
       vector<int> ans;
       while(!q.empty()){
           int k=q.size();
           ans.push_back((q.back())->val);
           while(k--){
               TreeNode* curr=q.front();
               q.pop_front();
               if(curr->left)q.push_back(curr->left);
               if(curr->right)q.push_back(curr->right);
           };
       };
       return ans;
    }
};