class Solution {
public:
    void dfsCount(vector<vector<int>> &adj,vector<int> &cnt,vector<int> &ans,int node=0,int par=-1){
        for(int nbr:adj[node]){
            if(nbr==par)continue;
            dfsCount(adj,cnt,ans,nbr,node);
            cnt[node]+=cnt[nbr];
            ans[node]+=ans[nbr]+cnt[nbr];
        };
        cnt[node]++;
    };
    void dfs(vector<vector<int>> &adj,vector<int> &cnt,vector<int> &ans,int n,int node=0,int par=-1){
        for(int nbr:adj[node]){
            if(nbr==par)continue;
            ans[nbr]=ans[node]+n-2*cnt[nbr];
            dfs(adj,cnt,ans,n,nbr,node);
        };
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n,0),cnt(n,0);
        vector<vector<int>> adj(n);
        for(auto i:edges){
            int a=i[0],b=i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        };
        dfsCount(adj,cnt,ans);
        dfs(adj,cnt,ans,n);
        return ans;
    }
};