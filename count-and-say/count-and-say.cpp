class Solution {
public:
    string say(string n){
        string ans;
        string curr=n;
        int counter=1;
        for(int i=0;i<curr.length()-1;i++){
            if(curr[i]==curr[i+1]){
                counter++;
            }else{
                ans+=to_string(counter);
                ans.push_back(curr[i]);
                counter=1;
            };
        };
        ans+=to_string(counter);
        ans.push_back(curr[curr.length()-1]);
        return ans;
    };
    string countAndSay(int n) {
       vector<string> dp(n);
        dp[0]="1";
        for(int i=1;i<n;i++){
            dp[i]=say(dp[i-1]);
        };
        return dp[n-1];
    }
};