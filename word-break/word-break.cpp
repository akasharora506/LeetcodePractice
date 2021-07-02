class Solution {
public:
    vector<int> dp;
    bool help(string s,unordered_set<string> &dict,int i=0){
        if(i==s.length())return dp[s.length()]=true;
        for(int j=i;j<s.length();j++){
            if(dict.count(s.substr(i,j-i+1))){
                if(dp[j+1]==-1)dp[j+1]=help(s,dict,j+1);
                if(dp[j+1])return true;
            };
        };
        return dp[i]=false;
    };
    bool wordBreak(string s, vector<string>& w) {
        dp.assign(s.length()+1,-1);
        unordered_set<string> dict(w.begin(),w.end());
        return help(s,dict);
    }
};