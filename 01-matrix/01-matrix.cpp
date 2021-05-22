class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> dist(m,vector<int> (n));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=!mat[i][j]?0:INT_MAX;
                if(!mat[i][j])q.push({i,j});
            };
        };
        vector<int> x{1,0,-1,0},y{0,1,0,-1};
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nbrX=curr.first+x[i],nbrY=curr.second+y[i];
               if(nbrX>=0&&nbrX<m&&nbrY>=0&&nbrY<n){ 
                   if(dist[nbrX][nbrY]>dist[curr.first][curr.second]+1){
                        dist[nbrX][nbrY]=dist[curr.first][curr.second]+1;
                        q.push({nbrX,nbrY});
                    };
               };
            };
        };
        
        return dist;
    }
};