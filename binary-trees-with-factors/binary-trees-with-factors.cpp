class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long int MOD=1e9+7;
        int n=arr.size();
        unordered_map<int,long> dp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            dp[arr[i]]=1;
            for(int j=0;arr[j]<=sqrt(arr[i]);j++){
                if(arr[i]%arr[j]==0){
                    long int other=arr[i]/arr[j];
                    if(dp[other]){
                        dp[arr[i]]=(dp[arr[i]]+dp[arr[j]]*dp[other]*(other==arr[j]?1:2))%MOD;
                    };
                };
            };
        };
        long int ans=0;
        for(auto i:dp)
            ans=(ans+i.second)%MOD;
        return ans;
    }
};