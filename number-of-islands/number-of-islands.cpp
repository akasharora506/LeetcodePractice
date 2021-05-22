class Solution {
public:
    void dfs(vector<vector<char>> &grid,int i,int j,int m,int n){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]=='0')
            return;
        grid[i][j]='0';
        vector<int> v{1,0,-1,0};
        for(int k=0;k<4;k++)
            dfs(grid,i+v[k],j+(v[(k+1)%4]),m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j,m,n);
                };
            };
        };   
        return ans;
    }
};