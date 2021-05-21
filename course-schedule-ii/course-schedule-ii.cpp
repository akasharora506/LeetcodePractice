class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n,0);
        queue<int> q;
        vector<int> ans,vis(n,0);
        vector<vector<int>> graph(n);
        for(auto i:prerequisites){
            graph[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        };
        for(int i=0;i<n;i++){
            if(indegree[i]==0&&vis[i]==0){
                q.push(i);
                vis[i]=1;
            };
        };
        while(!q.empty()){
            int c= q.front();
            q.pop();
            for(auto nbr:graph[c]){
                indegree[nbr]--;
            };
            for(int i=0;i<n;i++){
                if(indegree[i]==0&&vis[i]==0){
                    q.push(i);
                    vis[i]=1;
                };
            };
            ans.push_back(c);
        };
        reverse(ans.begin(),ans.end());
        if(count(vis.begin(),vis.end(),1)!=n)
            ans.clear();
        return ans;
    }
};