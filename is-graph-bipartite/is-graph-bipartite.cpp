class Solution {
public:
    bool dfs_helper(vector<vector<int>> &graph,vector<int> &visited,int curr=0,int parent=-1,int color=1){
        visited[curr]=color;
        for(int nbr:graph[curr]){
            if(visited[nbr]==0){
                bool ans=dfs_helper(graph,visited,nbr,curr,3-color); 
                if(ans==false)
                    return false;
            }else if(nbr!=parent&&visited[nbr]==color){
                return false;
            };
        };
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            vector<int> visited(n,0);
            if(dfs_helper(graph,visited,i)==false)
                return false;
        };
        return true;
    }
};