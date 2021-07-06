class Solution {
public:
    int M=1e9+7;
    int countVowelPermutation(int n) {
        long long int dp[n+1][5];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<5;j++){
                if(i==n-1){
                    dp[i][j]=1;
                    continue;
                };
                switch(j){
                    case 0:{
                        dp[i][j]=dp[i+1][1]%M;
                        break;}
                    case 1:{
                        dp[i][j]=(dp[i+1][0]%M+dp[i+1][2]%M)%M;
                        dp[i][j]=dp[i][j]%M;
                        break;}
                    case 2:{
                        dp[i][j]=(dp[i+1][0]%M+dp[i+1][1]%M+dp[i+1][3]%M+dp[i+1][4]%M)%M;
                        dp[i][j]=dp[i][j]%M;
                        break;}
                    case 3:{
                        dp[i][j]=(dp[i+1][2]%M+dp[i+1][4]%M)%M;
                        dp[i][j]=dp[i][j]%M;
                        break;}
                    case 4:{
                        dp[i][j]=dp[i+1][0]%M;
                        dp[i][j]=dp[i][j]%M;
                        break;}
                    default: break;
                };
            };
        };
        int ans=0;
        for(int j=0;j<5;j++){
            ans+=dp[0][j]%M;
            ans=ans%M;
        };
        return ans;
    }
};