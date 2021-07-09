class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][5];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<5;j++){
                if(i<=1){
                    dp[i][j]=i;
                    continue;
                };
                dp[i][j]=0;
                for(int k=j;k>=0;k--){
                    dp[i][j]+=dp[i-1][k];
                };
            };  
        };
        int ans=0;
        for(int i=0;i<5;i++)ans+=dp[n][i];
        return ans;
    }
};