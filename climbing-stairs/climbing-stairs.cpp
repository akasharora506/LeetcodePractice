class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++){
                if(i<3)dp[i]=i;
                else
                    dp[i]=dp[i-2]+dp[i-1];
        };
        return dp[n];
    }
};