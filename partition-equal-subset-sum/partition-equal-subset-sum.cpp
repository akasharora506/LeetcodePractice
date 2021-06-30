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
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        return help(dp,nums,n,sum/2);
    }
};