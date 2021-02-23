class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        int maxDig=sqrt(n);
        for(int i=1;i<=maxDig;i++){
            dp[i*i]=1;
        };
        for(int i=2;i<=n;i++){
            for(int j=1;j<=maxDig&&i>=j*j;j++){
              dp[i]=min(dp[i],dp[i-j*j]+1);  
            };
        };
        return dp[n];
    }
};