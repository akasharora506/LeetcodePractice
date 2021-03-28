class Solution {
public:
    int numSquares(int n) {
        vector<long long int> dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(floor(sqrt(i))==ceil(sqrt(i))){
                dp[i]=1;
                continue;
            };
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            };
        };
        return dp[n];
    }
};