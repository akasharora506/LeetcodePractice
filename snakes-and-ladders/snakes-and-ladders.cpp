class Solution {
public:
    int bfs(vector<vector<int>> &graph, int end,int start=0){
        unordered_map<int,int> dist;
        queue<int> q;
        q.push(start);
        dist[start]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int nbr:graph[curr]){
                if(dist.find(nbr)==dist.end()){
                    q.push(nbr);
                    dist[nbr]=dist[curr]+1;
                };
            };
        };
        return dist[graph.size()-1];
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        if(n*n<=6)
            return 1;
        if(board[0][0]!=-1)
            return -1;
        vector<vector<int>> graph(n*n);
        int curr=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                for(int k=1;k<=6;k++){
                    int newPos=curr+k;
                    if(newPos<n*n){
                        int x=n-newPos/n-1;
                        int y= (n-1-x)%2?n-newPos%n-1:newPos%n;
                        if(board[x][y]!=-1)
                            graph[curr].push_back(board[x][y]-1);
                        else
                            graph[curr].push_back(newPos);
                    };
                };
                curr++;
            };
        };
        return bfs(graph,n*n-1);
    }
};