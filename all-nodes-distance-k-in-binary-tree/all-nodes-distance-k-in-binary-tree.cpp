
class Solution {
public:
    void build(TreeNode* root,unordered_map<int,vector<int>> &m){
        if(!root)
            return;
        int curr=root->val;
        if(root->left){
            int l=root->left->val;
            m[curr].push_back(l);
            m[l].push_back(curr);
        };
        if(root->right){
            int r=root->right->val;
            m[curr].push_back(r);
            m[r].push_back(curr);
        };
        build(root->left,m);
        build(root->right,m);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> m;
        build(root,m);
        unordered_map<int,int> dist;
        for(auto i:m){
            dist[i.first]=INT_MAX;
        };
        dist[target->val]=0;
        queue<int> q;
        q.push(target->val);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int nbr:m[curr]){
                if(dist[nbr]==INT_MAX){
                    dist[nbr]=1+dist[curr];
                    q.push(nbr);
                };
            };
        };
        vector<int> ans;
        for(auto i:dist){
            if(i.second==k){
                ans.push_back(i.first);
            };
        };
        return ans;
    }
};