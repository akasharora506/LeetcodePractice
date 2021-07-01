class Solution {
public:
     bool help(vector<vector<int>> &dp,vector<int> &nums,int n,int req){
        if(n==0)return dp[n][req]=(req==0);
        if(dp[n-1][req]==-1)dp[n-1][req]=help(dp,nums,n-1,req);
        if(req>=nums[n-1]){
            if(dp[n-1][req-nums[n-1]]==-1)dp[n-1][req-nums[n-1]]=help(dp,nums,n-1,req-nums[n-1]);
            return dp[n-1][req]||dp[n-1][req-nums[n-1]];
        };
        return dp[n-1][req];       
    }
    bool canPartition(vector<int> &nums) {
        int sum=0,n=nums.size();
        for(int i:nums)sum+=i;
        if(sum%2)return false;
        vector<vector<bool>> dp(n+1,vector<bool> (sum+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    dp[i][j]=(j==0);
                }else if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                };
            };
        };
        return dp[n][sum/2];
    }
};