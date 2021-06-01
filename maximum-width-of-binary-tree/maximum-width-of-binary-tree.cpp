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
    long long widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        deque<pair<TreeNode*,long long>> q;
        q.push_back({root,0});
        long long ans=0;
        while(!q.empty()){
            long long k=q.size();
            auto f=q.front(),l=q.back();
            int mn=q.front().second;
            ans=max(ans,l.second-f.second+1);
            while(k--){
                auto curr=q.front();
                q.pop_front();
                if(curr.first->left)
                    q.push_back({curr.first->left,2*(curr.second-mn)});
                if(curr.first->right)
                    q.push_back({curr.first->right,2*(curr.second-mn)+1});
            };
        };
        return ans;
    }
};