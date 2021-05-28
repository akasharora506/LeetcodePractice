class Solution {
public:
    void floodFill(vector<vector<int>> &g,int i,int j,int n,int m,vector<pair<int,int>> &x){
        if(i<0||j<0||i>=n||j>=m||g[i][j]==0)
            return;
        x.push_back({i,j});
        g[i][j]=0;
        floodFill(g,i+1,j,n,m,x);
        floodFill(g,i-1,j,n,m,x);
        floodFill(g,i,j+1,n,m,x);
        floodFill(g,i,j-1,n,m,x);
    }
    int shortestBridge(vector<vector<int>>& g) {
        vector<pair<int,int>> x,y;
        int n=g.size(),m=g[0].size(),island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    island++;
                    if(island==1){
                        floodFill(g,i,j,n,m,x);
                    }else if(island==2){
                        floodFill(g,i,j,n,m,y);
                    }else{
                        break;
                    };
                };
                if(island>2)
                    break;
            };
        };
        int ans=INT_MAX;
        for(auto i:x){
            for(auto j:y){
                ans=min(ans,abs(i.first-j.first)+abs(i.second-j.second)-1);
            };
        };
        return ans;
    }
};