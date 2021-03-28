class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        if(n>=2)dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-2]+dp[i-1];
        };
        return dp[n];
    }
};