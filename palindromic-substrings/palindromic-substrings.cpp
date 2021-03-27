class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool> (n,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==j){
                    ans++;
                    dp[i][j]=1;
                }else if(i==j+1){
                    ans+=s[i]==s[j];
                    dp[i][j]=s[i]==s[j];
                }else{
                    if(dp[i-1][j+1]==1&&s[i]==s[j]){
                        ans++;
                        dp[i][j]=1;
                    };
                };
            };
        };
        return ans;
    }
};