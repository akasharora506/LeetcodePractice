class Solution {
public:
    void help(vector<string> &ans,int n,int o=0,int c=0,string curr=""){
        if(c>o||c>n||o>n)return;
        if(c==n&&o==n){
            ans.push_back(curr);
            return;
        };
        help(ans,n,o+1,c,curr+"(");
        help(ans,n,o,c+1,curr+")");
    };
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
        help(ans,n);
        return ans;
    }
};