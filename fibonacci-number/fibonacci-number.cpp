class Solution {
public:
    int fib(int n) {
        // vector<int> dp(n+1);
        // dp[0]=0;
        // for(int i=1;i<=n;i++){
        //     if(i==1){
        //         dp[i]=1;
        //         continue;
        //     };
        //     dp[i]=dp[i-1]+dp[i-2];
        // };
        // return dp[n];
        if(n==0||n==1)return n;
        return fib(n-1)+fib(n-2);
    }
};