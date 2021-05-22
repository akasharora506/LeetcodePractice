class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++) // converting ones connected to left boundary to zero
            if(grid[i][0])
                solve(grid, i, 0);
        
        for(int i = 0; i < grid.size(); i++) // converting ones connected to right boundary to zero
            if(grid[i][grid[0].size() - 1])
                solve(grid, i, grid[0].size() - 1);
        
        for(int i = 0; i < grid[0].size(); i++) // converting ones connected to upper boundary to zero
            if(grid[0][i])
                solve(grid, 0, i);
        
        for(int i = 0; i < grid[0].size(); i++)  // converting ones connected to lower boundary to zero
            if(grid[grid.size() - 1][i])
                solve(grid, grid.size() - 1, i);
        
        for(int i = 1; i < grid.size() - 1; i++)
            for(int j = 1; j < grid[0].size() - 1; j++) //calculating the number of ones left.
                if(grid[i][j])
                    ans++;
        
        return ans;
    }
    
    void solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;
        
		//Given below are traversals in every possible direction
		
        solve(grid, i + 1, j);
        solve(grid, i - 1, j);
        solve(grid, i, j + 1);
        solve(grid, i, j - 1);
    }
};