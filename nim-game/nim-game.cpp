class Solution {
public:
    bool canWinNim(int n) {
        vector<bool> dp(4,1);
        dp[3]=0;
        return dp[(n-1)%4];
    };
};