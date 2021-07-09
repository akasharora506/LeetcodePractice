class Solution {
public:
    bool isRot(int n){
        vector<int> dig;
        while(n){
            dig.push_back(n%10);
            n/=10;
        };
        bool flag=0;
        for(int i:dig){
            if(i==3 or i==4 or i==7)return 0;
            if(i==2 or i==5 or i==6 or i==9)flag=1;
        };
        return flag;
    };
    int rotatedDigits(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+isRot(i);
        };
        return dp[n];
    }
};