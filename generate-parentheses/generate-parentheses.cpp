class Solution {
public:
    bool isValid(string a){
        stack<char> s;
        for(char i:a){
            if(i=='('){
                s.push('(');
            }else{
                if(s.empty())
                    return 0;
                s.pop();
            };
        };
        return s.empty();
    };
    void backtrack(vector<string> &ans,string curr,int open,int close,int max){
        if(open==max&&close==max){
            if(isValid(curr))ans.push_back(curr);
            return;
        };
        if(open!=max&&close!=max){
            backtrack(ans,curr+'(',open+1,close,max);
            backtrack(ans,curr+')',open,close+1,max);
        }else if(open==max){
            backtrack(ans,curr+')',open,close+1,max);
        }else{
            backtrack(ans,curr+'(',open+1,close,max);
        };
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans,"",0,0,n);
        return ans;
    }
};