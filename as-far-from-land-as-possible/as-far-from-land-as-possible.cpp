class Solution {
public:
    vector<int> dir={1,0,-1,0};
    long long int bfs(vector<vector<int>> &g,int i,int j,int n ){
        queue<pair<pair<int,int>,int>> q;
        q.push({{i,j},0});
        vector<vector<int>> v(n,vector<int> (n,0));
        v[i][j]=0;
        while(!q.empty()){
            auto curr=q.front().first;
            int ans=q.front().second;
            q.pop();
            if(g[curr.first][curr.second]==1){
                return ans;
            };
            for(int i=0;i<4;i++){
                int x=curr.first+dir[i],y=curr.second+dir[(i+1)%4];
                if(x<0||y<0||x>=n||y>=n||v[x][y])continue;
                q.push({{x,y},ans+1});
                v[x][y]=1;
            };
        };
        return -1;
    };
    int maxDistance(vector<vector<int>>& g) {
        int n=g.size();
        long long int ans=INT_MIN;
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]){
                    q.push({i,j});
                    dist[i][j]=0;
                };
            };
        };
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=curr.first+dir[i],y=curr.second+dir[(i+1)%4];
                if(x<0||y<0||x>=n||y>=n||dist[x][y]<=
                   1+dist[curr.first][curr.second])continue;
                q.push({x,y});
                dist[x][y]=1+dist[curr.first][curr.second];
            };
        };
        for(auto i:dist){
            for(auto j:i)
                if(j!=INT_MAX)ans=max(ans,(long long)j);
        };
        return ans==INT_MIN||ans==0?-1:ans;
    }
};