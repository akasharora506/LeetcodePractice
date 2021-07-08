class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int ans=0;
        int m=a.size(),n=b.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                };
            };
        };
        return ans;
    }
};