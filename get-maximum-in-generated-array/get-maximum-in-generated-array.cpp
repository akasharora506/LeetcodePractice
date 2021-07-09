class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            if(i==1){
                dp[i]=1;
                continue;
            };
            int par=i/2;
            if(i%2){
                dp[i]=dp[par]+dp[par+1];
            }else{
                dp[i]=dp[par];
            };
        };
        return *max_element(dp.begin(),dp.end());
    }
};