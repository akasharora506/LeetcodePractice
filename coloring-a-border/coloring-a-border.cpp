class Solution {
public:
    void bfs(vector<vector<int>>& g,vector<vector<bool>>& v, int r, int c, int color){
        int m=g.size(),n=g[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        v[r][c]=1;
        int par=g[r][c];
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int i=curr.first,j=curr.second;  
            vector<pair<int,int>> nbrs={{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
            bool shouldColor=0;
            for(auto nbr:nbrs){
                int ni=nbr.first,nj=nbr.second;
                if(ni==-1||ni==m||nj==-1||nj==n||(!v[ni][nj]&&g[ni][nj]!=par)){
                    shouldColor=1;
                };
                if(ni>=0&&ni<m&&nj>=0&&nj<n&&!v[ni][nj]&&g[ni][nj]==par){
                    v[ni][nj]=1;
                    q.push({ni,nj});
                };
            };
            if(shouldColor)g[i][j]=color;
        };

    }
    vector<vector<int>> colorBorder(vector<vector<int>>& g, int i, int j, int color) {        vector<vector<bool>> v(g.size(),vector<bool> (g[0].size(),0));
        bfs(g,v,i,j,color);
        return g;
    }
};